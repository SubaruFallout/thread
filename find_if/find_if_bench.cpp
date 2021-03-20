#include "benchmark/benchmark.h"
#include "find_if.h"

bool FastPredicat(int64_t x) {
  return x % 14 == 0;
}

bool LongPredicat(int64_t x) {
  for (int i = 2; i < x; i++) {
    if (x % i) {
      return false;
    }
  }
  return true;
}

static void BM_TEST_FAST1(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 1);
  }
}

static void BM_TEST_FAST2(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 2);
  }
}

static void BM_TEST_FAST3(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 3);
  }
}

static void BM_TEST_FAST4(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 4);
  }
}

static void BM_TEST_FAST5(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 5);
  }
}

static void BM_TEST_FAST6(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, FastPredicat, 6);
  }
}

static void BM_TEST_LONG1(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 1);
  }
}

static void BM_TEST_LONG2(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 2);
  }
}

static void BM_TEST_LONG3(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 3);
  }
}

static void BM_TEST_LONG4(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 4);
  }
}

static void BM_TEST_LONG5(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 5);
  }
}

static void BM_TEST_LONG6(benchmark::State& state) {
  for (auto _ : state) {
    int l = 1;
    int r = 100000;
    std::vector<int64_t> ans = FindIf(l, r, LongPredicat, 6);
  }
}

BENCHMARK(BM_TEST_FAST1);
BENCHMARK(BM_TEST_FAST2);
BENCHMARK(BM_TEST_FAST3);
BENCHMARK(BM_TEST_FAST4);
BENCHMARK(BM_TEST_FAST5);
BENCHMARK(BM_TEST_FAST6);
BENCHMARK(BM_TEST_LONG1);
BENCHMARK(BM_TEST_LONG2);
BENCHMARK(BM_TEST_LONG3);
BENCHMARK(BM_TEST_LONG4);
BENCHMARK(BM_TEST_LONG5);
BENCHMARK(BM_TEST_LONG6);


BENCHMARK_MAIN();