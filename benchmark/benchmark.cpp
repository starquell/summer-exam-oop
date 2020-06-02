#include <benchmark/benchmark.h>

static auto test (benchmark::State& state) {
    for (auto _ : state) {

    }
}

BENCHMARK(test);
BENCHMARK_MAIN();