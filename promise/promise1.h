#define PROMISE_NOT_IMPLEMENTED
#ifndef PROMISE_H
#define PROMISE_H

#include <condition_variable>
#include <mutex>
#include <functional>
#include <thread>
#include <iostream>

template<typename ResultType>
void Solve(const std::function<ResultType()>& predicate,
           ResultType& result1, bool& flag1,
           std::mutex& m1,
           std::condition_variable& cv1);

template<typename ResultType>
class Promise {
 public:
  Promise(const std::function<ResultType()>& predicate);
  // void Solve(const std::function<ResultType()>& predicate,
  //            ResultType& result1, bool& flag1,
  //            std::mutex& m1,
  //            std::condition_variable& cv1);
  ResultType Wait();
  ~Promise();

 private:
  std::mutex m;
  std::condition_variable cv;
  ResultType result;
  bool flag = false;
  std::thread f;
};

template<typename ResultType>
Promise<ResultType>::Promise(const std::function<ResultType()>& predicate) {
  std::thread t([&]() {
    Solve(predicate, result, flag, m, cv);
  });
  f = std::move(t);
}

template<typename ResultType>
void Solve(const std::function<ResultType()>& predicate,
           ResultType& result1, bool& flag1,
           std::mutex& m1,
           std::condition_variable& cv1) {
  {
    std::lock_guard<std::mutex> lk(m1);
    result1 = predicate();
    flag1 = true;
  }
  cv1.notify_one();
}

template<typename ResultType>
ResultType Promise<ResultType>::Wait() {
  // //if (flag == false) {
   //return result;
  // // }
  while(!flag){}
  //std::unique_lock<std::mutex> lk(m);
 // cv.wait(lk, [&]() { return flag; });
 // lk.unlock();
  return result;
}

template<typename ResultType>
Promise<ResultType>::~Promise() {
  f.join();
}

#endif  // PROMISE_H
