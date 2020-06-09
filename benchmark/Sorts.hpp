#pragma once

#include "../include/Sorts/Quick.hpp"
#include "../include/Sorts/Bucket.hpp"
#include "../include/Sorts/Counting.hpp"
#include "../include/Sorts/Radix.hpp"
#include "../include/Sorts/Selection.hpp"
#include "../include/Sorts/Insertion.hpp"
//#include "../include/Sorts/Merge.hpp"
#include "../include/Random.hpp"

using namespace exam::sort;

void default_quick (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));

    for (auto _ : state) {
        quick_sort(vec.begin(), vec.end());
    }
}

void parallel_quick (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));

    for (auto _ : state) {
        quick_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
    }
}

void default_bucket (benchmark::State& state) {
    auto vec = exam::random<std::vector<float>> (state.range(0), 0, 1);

    for (auto _ : state) {
        bucket_sort(vec.begin(), vec.end());
    }
}

void parallel_bucket (benchmark::State& state) {
    auto vec = exam::random<std::vector<float>> (state.range(0), 0, 1);

    for (auto _ : state) {
        bucket_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
    }
}

//void default_merge (benchmark::State& state) {
//    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));
//
//    for (auto _ : state) {
//        merge_sort(vec.begin(), vec.end());
//    }
//}
//
//void parallel_merge (benchmark::State& state) {
//    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));
//
//    for (auto _ : state) {
//        merge_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
//    }
//}

void default_radix (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), -state.range(0), state.range(0));

    for (auto _ : state) {
        radix_sort(vec.begin(), vec.end());
    }
}

void parallel_radix (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), -state.range(0), state.range(0));

    for (auto _ : state) {
        radix_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
    }
}

void default_counting (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));

    for (auto _ : state) {
        counting_sort(vec.begin(), vec.end());
    }
}

void default_selection (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));

    for (auto _ : state) {
        selection_sort(vec.begin(), vec.end());
    }
}

void default_insertion (benchmark::State& state) {
    auto vec = exam::random<std::vector<int>> (state.range(0), 0, state.range(0));

    for (auto _ : state) {
        insertion_sort(vec.begin(), vec.end());
    }
}

BENCHMARK(default_quick)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(parallel_quick)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(default_bucket)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(parallel_bucket)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
//BENCHMARK(default_merge)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
//BENCHMARK(parallel_merge)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(default_radix)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(parallel_radix)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(default_counting)->RangeMultiplier(10)->Range(100, 10000000)->Unit(benchmark::kMillisecond);
BENCHMARK(default_selection)->RangeMultiplier(10)->Range(100, 100000)->Unit(benchmark::kMillisecond);
BENCHMARK(default_insertion)->RangeMultiplier(10)->Range(100, 100000)->Unit(benchmark::kMillisecond);
