#pragma once

#include "../include/HashTables/StaticCoalested.hpp"
#include "../include/Random.hpp"

#include <algorithm>
#include <unordered_set>

using namespace exam::hashtable;

SCENARIO_TEMPLATE ("Hash tables", HashTable,
        StaticCoalestedHashTable<int, 10>)
{
    auto elems = std::unordered_set<typename HashTable::value_type> {};
    auto table = HashTable{};

    for (auto i = 0; i < HashTable::max_size(); ++i) {
        REQUIRE(table.size() == elems.size());
        REQUIRE(std::is_permutation (table.begin(), table.end(), elems.begin()));

        const auto to_insert = exam::random<typename HashTable::value_type> ();
        table.insert(to_insert);
        elems.insert(to_insert);

        REQUIRE (table.find(to_insert) != table.end());
    }

    for (auto i = 0; i < HashTable::max_size(); ++i) {
        REQUIRE(table.size() == elems.size());
        REQUIRE(std::is_permutation (table.begin(), table.end(), elems.begin()));

        const auto to_erase = *table.begin();

        table.erase(to_erase);
        elems.erase(to_erase);

        REQUIRE (table.find(to_erase) == table.end());
    }
}