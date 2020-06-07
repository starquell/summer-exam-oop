#pragma once

#include "../include/Trees/RedBlack.hpp"
#include "../include/Trees/Splay.hpp"
#include "../include/Trees/AVL.hpp"

using namespace exam::tree;

SCENARIO_TEMPLATE("Red-Black and Splay Tree", Tree,
                  SplayTree<int, std::less<>>,
                  RedBlackTree<int, std::less<>>,
                  AVLTree<int, std::less<>>)
{
    static constexpr std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor from iterators test") {
        auto tree = Tree(elems.begin(), elems.end());

        auto it = tree.begin();

                REQUIRE(*it == 1);
                REQUIRE(*(++it) == 2);
                REQUIRE(*(++it) == 4);
                REQUIRE(*(++it) == 24);
                REQUIRE(*(++it) == 103);
    }

    SUBCASE("Constructor's from iterators test") {
        auto tree = Tree({elems[0], elems[1], elems[2], elems[3], elems[4]});

        auto it = tree.begin();

                REQUIRE(*it == 1);
                REQUIRE(*(++it) == 2);
                REQUIRE(*(++it) == 4);
                REQUIRE(*(++it) == 24);
                REQUIRE(*(++it) == 103);
    }

    auto tree = Tree(elems.begin(), elems.end());

    SUBCASE ("Deep copy") {
        auto copied = Tree(tree);

                REQUIRE(*copied.begin() == 1);
                REQUIRE(*(copied.begin() + 1) == 2);
                REQUIRE(*(copied.begin() + 2) == 4);
                REQUIRE(*(copied.begin() + 3) == 24);
                REQUIRE(*(copied.begin() + 4) == 103);
    }

    SUBCASE("Insert") {
        tree.insert(100);
                REQUIRE(tree.search(100));
    }

            SUBCASE("Erase") {
                REQUIRE(tree.search(elems[0]));
                tree.erase(elems[0]);

                REQUIRE_FALSE(tree.search(elems[0]));
    }

            SUBCASE("Size") {
                REQUIRE(tree.size() == std::distance(elems.begin(), elems.end()));
    }
}



