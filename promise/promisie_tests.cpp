#include "promise.h"
#include "gtest.h"

int Fin() {
  sleep(3);
  throw std::runtime_error("Division by zero!");
}

int Fun() {
  sleep(3);
  return 15;
}

void Bruh() {}

TEST(Hehe, Hehe) {
  Promise<int> GF(Fin);
  Promise<int> GD(Fin);
  Promise<int> GR(Fin);
  int ans, a2, a3;
  try {
    ans = GD.Wait();
  } catch (const std::exception& e) {
    std::cerr << e.what() << " ans\n" << std::endl;
  }
  try {
    a2 = GR.Wait();
  } catch (const std::exception& e) {
    std::cerr << e.what() << " a2\n" << std::endl;
  }
  try {
    a3 = GF.Wait();
  } catch (const std::exception& e) {
    std::cerr << e.what() << " a3\n" << std::endl;
  }
  Promise<int> H1(Fun);
  Promise<int> H2(Fun);
  try {
    ans = H1.Wait();
  } catch (const std::exception& e) {
    std::cerr << e.what() << " lol\n";
  }
  try {
    a3 = H2.Wait();
  } catch (const std::exception& e) {
    std::cerr << e.what() << " kek\n";
  }
  Promise<void> bruh(Bruh);
  bruh.Wait();
  ASSERT_EQ(ans, 15);
  ASSERT_EQ(a3, 15);
}
