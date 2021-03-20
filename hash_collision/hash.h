#ifndef HASH_H_
#define HASH_H_

#include <algorithm>
#include <atomic>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <utility>
#include <vector>

const int flex = 1;

class Map {
 public:
  Map();
  ~Map() = default;
  void Add(int64_t hash, const std::string& s);

 public:
  int kCount = 214000;
  std::vector<std::vector<std::string>> dict_;

 private:
  std::vector<std::unique_ptr<std::mutex>> mutex_;
};

int64_t Hash(const std::string& s, int64_t p, int64_t m);

std::string FindCollision(const std::string& a,
                          int64_t p,
                          int64_t m,
                          uint8_t concurrency = 1);

void Find(int64_t p,
          int64_t m,
          int lower_bound,
          int upper_bound,
          int len,
          const std::shared_ptr<Map>& map,
          const std::string& a,
          const std::shared_ptr<std::string>& ans,
          const std::shared_ptr<std::mutex>& mut,
          const std::shared_ptr<bool>& flag);

void Solve(int64_t p,
           int64_t m,
           int lower_bound,
           int upper_bound,
           int len,
           const std::shared_ptr<Map>& map);

#endif  // HASH_H_
