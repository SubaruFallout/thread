#include "hash.h"

Map::Map() {
  mutex_.resize(kCount);
  for (int i = 0; i < kCount; i++) {
    std::unique_ptr<std::mutex> mutex(new std::mutex);
    mutex_[i] = std::move(mutex);
  }
  dict_.resize(kCount);
}

void Map::Add(int64_t hash, const std::string& s) {
  hash %= kCount;
  mutex_[hash]->lock();
  dict_[hash].push_back(s);
  mutex_[hash]->unlock();
}

int64_t Hash(const std::string& s, int64_t p, int64_t m) {
  int64_t result = 0;
  for (char ch : s) {
    result = (__int128_t(result) * p + (ch - 'a' + 1)) % m;
  }
  return result;
}

std::string FindCollision(const std::string& a,
                          int64_t p,
                          int64_t m,
                          uint8_t concurrency) {
  std::shared_ptr<Map> map = std::make_shared<Map>();
  std::vector<std::thread> process(concurrency);
  std::shared_ptr<bool> flag = std::make_shared<bool>();
  *flag = false;
  std::shared_ptr<std::mutex> mut = std::make_shared<std::mutex>();
  int len = 0;
  while (true) {
    map = std::make_shared<Map>();
    len++;
    int alpha = 26;
    int lower_bound = 0;
    int upper_bound = 1;
    for (int i = 0; i < len; i++) {
      upper_bound *= alpha;
    }
    upper_bound--;
    int step = (upper_bound - lower_bound + 1) / concurrency;
    if ((upper_bound - lower_bound + 1) % concurrency != 0) {
      step++;
    }
    for (int i = 0; i < concurrency; i++) {
      std::thread thread(Solve,
                         p,
                         m,
                         lower_bound,
                         std::min(lower_bound + step - 1, upper_bound),
                         len,
                         std::ref(map));
      lower_bound += step;
      process[i] = std::move(thread);
    }
    for (int i = 0; i < concurrency; i++) {
      process[i].join();
    }
    lower_bound = 0;
    std::shared_ptr<std::string> ans = std::make_shared<std::string>();
    for (int i = 0; i < concurrency; i++) {
      std::thread thread(Find,
                         p,
                         m,
                         lower_bound,
                         std::min(lower_bound + step - 1, upper_bound),
                         len,
                         std::ref(map),
                         std::ref(a),
                         std::ref(ans),
                         std::ref(mut),
                         std::ref(flag));
      lower_bound += step;
      process[i] = std::move(thread);
    }
    for (int i = 0; i < concurrency; i++) {
      process[i].join();
    }
    process.clear();
    if (*flag) {
      return *ans;
    }
  }
}

void Find(int64_t p,
          int64_t m,
          int lower_bound,
          int upper_bound,
          int len,
          const std::shared_ptr<Map>& map,
          const std::string& a,
          const std::shared_ptr<std::string>& ans,
          const std::shared_ptr<std::mutex>& mut,
          const std::shared_ptr<bool>& flag) {
  int64_t h = Hash(a, p, m);
  std::string s;
  for (int i = lower_bound; i <= upper_bound; i++) {
    mut->lock();
    bool gg = *flag;
    mut->unlock();
    if (gg) {
      return;
    }
    s = "";
    int code = i;
    for (int k = 0; k < len; k++) {
      s += static_cast<char>(static_cast<int>('a') + code % 26);
      code /= 26;
    }
    int64_t hash = Hash(s, p, m);
    for (int u = 0; u < len; u++) {
      hash *= p;
      hash %= m;
    }
    hash = (m + h - hash) % m;
    int mode_hash = hash % map->kCount;
    for (int j = 0; j < map->dict_[mode_hash].size(); j++) {
      if (hash == Hash(map->dict_[mode_hash][j], p, m)) {
        if (s + map->dict_[mode_hash][j] != a) {
          mut->lock();
          if (*flag == false) {
            *ans = s + map->dict_[mode_hash][j];
            *flag = true;
          }
          mut->unlock();
          return;
        }
      }
    }
  }
}

void Solve(int64_t p,
           int64_t m,
           int lower_bound,
           int upper_bound,
           int len,
           const std::shared_ptr<Map>& map) {
  std::string s;
  for (int i = lower_bound; i <= upper_bound; i++) {
    s = "";
    int code = i;
    for (int k = 0; k < len; k++) {
      s += static_cast<char>(static_cast<int>('a') + code % 26);
      code /= 26;
    }
    map->Add(Hash(s, p, m), s);
  }
}
