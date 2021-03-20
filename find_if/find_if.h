#ifndef FIND_IF_H_
#define FIND_IF_H_

#include <algorithm>
#include <cstdint>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>
#include <vector>

class Vector {
 public:
  Vector() = default;
  void Add(int64_t x);
  std::vector<int64_t> Get();

 private:
  std::vector<int64_t> ans_;
  std::mutex mutex_;
};

std::vector<int64_t> FindIf(int64_t lower_bound,
                            int64_t upper_bound,
                            const std::function<bool(int64_t)>& predicate,
                            uint8_t concurrency = 1);

void Solve(const std::function<bool(int64_t)>& predicate,
           int64_t lower_bound,
           int64_t upper_bound,
           const std::shared_ptr<Vector>& ans);

#endif  // FIND_IF_H_
