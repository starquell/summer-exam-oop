#pragma once

#include "../include/Set.hpp"

#include <set>

TEST_CASE ("Set") {
    using namespace exam;

    using StledSet = Set<std::set<int>>;
    StledSet set;

    set.insert(1);
    set.insert(3);
    set.insert(5);

    CHECK (set == StledSet{1, 3, 5});

    set.erase(5);

    CHECK (set == StledSet {1, 3});
    CHECK (set.union_with(StledSet {3, 5, 6, 7}) == StledSet {1, 3, 5, 6, 7});
    CHECK (set.difference(StledSet {3, 5, 6, 7}) == StledSet {1});
    CHECK (set.intersection(StledSet {3, 5, 6, 7}) == StledSet {3});
    CHECK (set.symmetric_difference(StledSet {3, 5, 6, 7}) == StledSet {1, 5, 6, 7});
}