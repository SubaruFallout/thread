#include "benchmark/benchmark.h"
#include "hash.h"
using namespace std;

static void BM_TEST_LLL1(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 1);
  }
}

static void BM_TEST_LLL2(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 2);
  }
}

static void BM_TEST_LLL3(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 3);
  }
}

static void BM_TEST_LLL4(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

static void BM_TEST_LLL5(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 5);
  }
}

static void BM_TEST_LLL6(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 101;
    int len = 1;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 6);
  }
}

static void BM_TEST_HHH1(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 1);
  }
}

static void BM_TEST_HHH2(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 2);
  }
}

static void BM_TEST_HHH3(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 3);
  }
}

static void BM_TEST_HHH4(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

static void BM_TEST_HHH5(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 5);
  }
}

static void BM_TEST_HHH6(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 6);
  }
}

static void BM_TEST_HHH8(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int m = 998'244'353;
    int len = 30;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 8);
  }
}

static void BM_TEST_P29(benchmark::State& state) {
  for (auto _ : state) {
    int p = 29;
    int64_t m = 738'832'927'927;
    int len = 60;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

static void BM_TEST_P101(benchmark::State& state) {
  for (auto _ : state) {
    int p = 101;
    int64_t m = 738'832'927'927;
    int len = 60;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

static void BM_TEST_P1103(benchmark::State& state) {
  for (auto _ : state) {
    int p = 101;
    int64_t m = 738'832'927'927;
    int len = 60;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

static void BM_TEST_P3571(benchmark::State& state) {
  for (auto _ : state) {
    int p = 1103;
    int64_t m = 738'832'927'927;
    int len = 60;
    std::string a;
    for(int i = 0; i < len; i++) {
      a += 'a';
    }
    string ans = FindCollision(a, p, m, 4);
  }
}

BENCHMARK(BM_TEST_LLL1);
BENCHMARK(BM_TEST_LLL2);
BENCHMARK(BM_TEST_LLL3);
BENCHMARK(BM_TEST_LLL4);
BENCHMARK(BM_TEST_LLL5);
BENCHMARK(BM_TEST_LLL6);
BENCHMARK(BM_TEST_HHH1);
BENCHMARK(BM_TEST_HHH2);
BENCHMARK(BM_TEST_HHH3);
BENCHMARK(BM_TEST_HHH4);
BENCHMARK(BM_TEST_HHH5);
BENCHMARK(BM_TEST_HHH6);
BENCHMARK(BM_TEST_HHH8);
BENCHMARK(BM_TEST_P29);
BENCHMARK(BM_TEST_P101);
BENCHMARK(BM_TEST_P1103);
BENCHMARK(BM_TEST_P3571);



BENCHMARK_MAIN();