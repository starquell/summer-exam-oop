#pragma once

#include "../include/Set.hpp"

#include <set>

using namespace exam;

template <template<typename...> typename Container>
void test_set (Container<int>) {

    using MySet =  Set<int, Container>;
    MySet set;

    set.insert(1);
    set.insert(3);
    set.insert(5);

    CHECK (set == MySet{1, 3, 5});

    set.erase(5);

    CHECK (set == MySet {1, 3});
    CHECK (set.union_with(MySet {3, 5, 6, 7}) == MySet {1, 3, 5, 6, 7});
    CHECK (set.difference(MySet {3, 5, 6, 7}) == MySet {1});
    CHECK (set.intersection(MySet {3, 5, 6, 7}) == MySet {3});
    CHECK (set.symmetric_difference(MySet {3, 5, 6, 7}) == MySet {1, 5, 6, 7});
}

TEST_CASE ("Set") {

   test_set(std::unordered_set<int>{});
   test_set(tree::AVLTree<int>{});
   test_set(tree::SplayTree<int>{});

}