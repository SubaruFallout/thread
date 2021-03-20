#include "find_if.h"

void Vector::Add(int64_t x) {
  mutex_.lock();
  ans_.push_back(x);
  mutex_.unlock();
}

std::vector<int64_t> Vector::Get() {
  return ans_;
}

std::vector<int64_t> FindIf(int64_t lower_bound,
                            int64_t upper_bound,
                            const std::function<bool(int64_t)>& predicate,
                            uint8_t concurrency) {
  std::vector<std::thread> process(concurrency);
  std::shared_ptr<Vector> ans = std::make_shared<Vector>();
  int64_t step = (upper_bound - lower_bound + 1) / concurrency;
  if ((upper_bound - lower_bound + 1) % concurrency != 0) {
    step++;
  }
  for (int i = 0; i < concurrency; i++) {
    std::thread thread(Solve,
                       std::ref(predicate),
                       lower_bound,
                       std::min(lower_bound + step - 1, upper_bound),
                       std::ref(ans));
    lower_bound += step;
    process[i] = std::move(thread);
  }
  for (int i = 0; i < concurrency; i += 1) {
    process[i].join();
  }
  return ans->Get();
}

void Solve(const std::function<bool(int64_t)>& predicate,
           int64_t lower_bound,
           int64_t upper_bound,
           const std::shared_ptr<Vector>& ans) {
  for (int i = lower_bound; i <= upper_bound; i++) {
    if (predicate(i)) {
      ans->Add(i);
    }
  }
}
