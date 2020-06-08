#pragma once

#include "../include/HashTables/StaticCoalested.hpp"

#include <unordered_set>


template <typename... Hashtable>
static void ht_insertion (benchmark::State& state, Hashtable&&... table) {

    for (auto _ : state) {
        (table.insert (exam::random<typename Hashtable::value_type>()), ...);
    }
}

template <typename... Hashtable>
static void ht_erasing (benchmark::State& state, Hashtable&&... table) {

    for (auto _ : state) {
        (table.erase(*table.begin()), ...);
    }
}

template <typename... Hashtable>
static void ht_iteration (benchmark::State& state, Hashtable&&... table) {

    auto begin = (*table.begin(), ...);

    for (auto _ : state) {
        ++begin;
    }
}


BENCHMARK_CAPTURE(ht_insertion, StaticCoalestTable_insertion, (exam::hashtable::StaticCoalestedHashTable<int, 10>{}));
BENCHMARK_CAPTURE(ht_insertion, unordered_set_insertion, std::unordered_set<int>{});

BENCHMARK_CAPTURE(ht_insertion, StaticCoalestTable_insertion, (exam::hashtable::StaticCoalestedHashTable<int, 100>{}));
BENCHMARK_CAPTURE(ht_insertion, unordered_set_insertion, std::unordered_set<int>{});

BENCHMARK_CAPTURE(ht_insertion, StaticCoalestTable_insertion, (exam::hashtable::StaticCoalestedHashTable<int, 1000>{}));
BENCHMARK_CAPTURE(ht_insertion, unordered_set_insertion, std::unordered_set<int>{});

BENCHMARK_CAPTURE(ht_erasing, StaticCoalestTable_erasing,
        exam::random<exam::hashtable::StaticCoalestedHashTable<int, 10>>())->Iterations(10);
BENCHMARK_CAPTURE(ht_erasing, unordered_set_erasing,
        exam::random<std::unordered_set<int>>(10))->Iterations(10);

BENCHMARK_CAPTURE(ht_erasing, StaticCoalestTable_erasing,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 100>>())->Iterations(100);
BENCHMARK_CAPTURE(ht_erasing, unordered_set_erasing,
                  exam::random<std::unordered_set<int>>(100))->Iterations(100);

BENCHMARK_CAPTURE(ht_erasing, StaticCoalestTable_erasing,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 1000>>())->Iterations(100);
BENCHMARK_CAPTURE(ht_erasing, unordered_set_erasing,
                  exam::random<std::unordered_set<int>>(1000))->Iterations(100);
BENCHMARK_CAPTURE(ht_erasing, StaticCoalestTable_erasing,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 10>>())->Iterations(10);
BENCHMARK_CAPTURE(ht_erasing, unordered_set_erasing,
                  exam::random<std::unordered_set<int>>(10))->Iterations(10);

BENCHMARK_CAPTURE(ht_iteration, StaticCoalestTable_iteration,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 10>>())->Iterations(10);
BENCHMARK_CAPTURE(ht_iteration, unordered_set_iteration,
                  exam::random<std::unordered_set<int>>(10))->Iterations(10);

BENCHMARK_CAPTURE(ht_iteration, StaticCoalestTable_iteration,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 100>>())->Iterations(100);
BENCHMARK_CAPTURE(ht_iteration, unordered_set_iteration,
                  exam::random<std::unordered_set<int>>(100))->Iterations(100);

BENCHMARK_CAPTURE(ht_iteration, StaticCoalestTable_iteration,
                  exam::random<exam::hashtable::StaticCoalestedHashTable<int, 1000>>())->Iterations(1000);
BENCHMARK_CAPTURE(ht_iteration, unordered_set_iteration ,
                  exam::random<std::unordered_set<int>>(1000))->Iterations(1000);

