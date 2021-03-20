#include <iostream>

#include "find_if.h"
#include "gtest.h"

bool Predicat(int64_t x) {
  return x % 4 == 3;
}

bool SleepPredicat(int64_t x) {
  sleep(0.01);
  return x % 10 == 1;
}

TEST(FindIfTest, BaseChecking) {
  int l = 1;
  int r = 1000;
  std::vector<int64_t> true_ans;
  for (int64_t i = l; i <= r; i++) {
    if (Predicat(i)) {
      true_ans.push_back(i);
    }
  }
  std::vector<int64_t> ans = FindIf(l, r, Predicat, 1);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, Predicat, 2);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, Predicat, 3);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, Predicat, 4);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, Predicat, 5);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, Predicat, 6);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
}

TEST(FindIfTest, CheckWithSleepInPredicate) {
  int l = -1000000;
  int r = 1000000;
  std::vector<int64_t> true_ans;
  for (int64_t i = l; i <= r; i++) {
    if (SleepPredicat(i)) {
      true_ans.push_back(i);
    }
  }
  std::vector<int64_t> ans = FindIf(l, r, SleepPredicat, 1);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, SleepPredicat, 2);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, SleepPredicat, 3);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, SleepPredicat, 4);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, SleepPredicat, 5);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
  ans = FindIf(l, r, SleepPredicat, 6);
  std::sort(ans.begin(), ans.end());
  ASSERT_EQ(ans, true_ans);
}
