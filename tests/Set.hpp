#pragma once

#include "../include/Set.hpp"
#include "../include/Map.hpp"

#include <set>

using namespace exam;

template <typename Set>
void test_set (Set&& set) {

    set.insert(1);
    set.insert(3);
    set.insert(5);

    CHECK (set == Set{1, 3, 5});

    set.erase(5);

    CHECK (set == Set {1, 3});
    CHECK (set.union_with(Set {3, 5, 6, 7}) == Set {1, 3, 5, 6, 7});
    CHECK (set.difference(Set {3, 5, 6, 7}) == Set {1});
    CHECK (set.intersection(Set {3, 5, 6, 7}) == Set {3});
    CHECK (set.symmetric_difference(Set {3, 5, 6, 7}) == Set {1, 5, 6, 7});
}

template <typename Map>
void test_map (Map&& map) {

    map.insert({1, "aa"});
    map.insert({3, "bb"});
    map.insert({5, "cc"});

    CHECK (map == Map {{1, "aa"}, {3, "bb"}, {5, "cc"}});

    map.erase(5);

    CHECK (map == Map {{1, "aa"}, {3, "bb"}});

    CHECK (map[1] == "aa");
    CHECK (map[3] == "bb");
}

TEST_CASE ("Set") {

   test_set(exam::Set<int, std::unordered_set>{});
   test_set(exam::Set<int, tree::AVLTree>{});
   test_set(exam::Set<int ,tree::SplayTree>{});

   test_map(exam::Map<int, std::string, std::unordered_set>{});
   test_map(exam::Map<int, std::string, tree::AVLTree>{});
   test_map(exam::Map<int, std::string, tree::SplayTree>{});
}