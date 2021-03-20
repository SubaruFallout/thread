#include <iostream>
#include "gtest.h"
#include "hash.h"

TEST(Hehe, Test) {
  std::string flex;
  for (int i = 0; i < 2; i++) {
    flex = "f";
  }
  int p = 29;
  // int64_t m = 1'000'000'007;
  int64_t m = 998'244'353;
  // int64_t m = 101;
  std::string ans = FindCollision(flex, p, m, 8);
  EXPECT_EQ(Hash(flex, p, m), Hash(ans, p, m));
  // std::cerr << ans;
}

TEST(Hehe, OneWord) {
  std::string flex;
  for (int i = 0; i < 26; i++) {
    flex = "r";
    int p = 29;
    int64_t m = 998'244'353;
    std::string ans = FindCollision(flex, p, m, 1);
    std::cerr << flex << ' ' << i << ' ' << ans << ' ' << i << '\n';
    ASSERT_EQ(Hash(flex, p, m), Hash(ans, p, m));
  }
}