#ifndef PROMISE_H_
#define PROMISE_H_
#define PROMISE_SUPPORTS_EXCEPTIONS

#include <condition_variable>
#include <mutex>
#include <functional>
#include <thread>
#include <iostream>

struct Addons {
  std::mutex m;
  std::condition_variable cv;
  std::exception_ptr eptr;
  bool flag = false;
};

template<typename ResultType>
void Solve(std::function<ResultType()> predicate,
           const std::shared_ptr<ResultType>& result,
           const std::shared_ptr<Addons>& addons);

template<typename ResultType>
class Promise {
 public:
  explicit Promise(const std::function<ResultType()>& predicate);
  ResultType Wait();
  ~Promise();

 private:
  std::shared_ptr<ResultType> result;
  std::shared_ptr<Addons> addons;
  std::thread f;
};

template<typename ResultType>
Promise<ResultType>::Promise(const std::function<ResultType()>& predicate) {
  addons = std::make_shared<Addons>();
  result = std::make_shared<ResultType>();
  std::thread t([this, predicate]() {
    Solve(predicate, result, addons);
  });
  f = std::move(t);
}

template<typename ResultType>
void Solve(std::function<ResultType()> predicate,
           const std::shared_ptr<ResultType>& result,
           const std::shared_ptr<Addons>& addons) {
  {
    std::lock_guard<std::mutex> lk(addons->m);
    try {
      result.get() = predicate();
    } catch (...) {
      addons->eptr = std::current_exception();
    }
    addons->flag = true;
  }
  addons->cv.notify_one();
}

template<typename ResultType>
ResultType Promise<ResultType>::Wait() {
  try {
    if (addons->eptr) {
      std::rethrow_exception(addons->eptr);
    }
  } catch (const std::exception& e) {
    throw e;
  }
  std::unique_lock<std::mutex> lk(addons->m);
  addons->cv.wait(lk, [this]() { return addons->flag; });
  lk.unlock();
  return result.get();
}

template<typename ResultType>
Promise<ResultType>::~Promise() {
  f.join();
}

#endif  // PROMISE_H_
