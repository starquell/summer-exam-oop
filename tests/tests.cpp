#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../3rdparty/doctest/doctest.h"
#include "../include/Trees/RedBlack.hpp"
#include "../include/Trees/Splay.hpp"
#include "../include/Trees/AVL.hpp"
#include "../include/LinkedLists/DoubleLinked.hpp"

using namespace exam::tree;

SCENARIO_TEMPLATE("Red-Black and Splay Tree", Tree,
        SplayTree<int, std::less<>>, RedBlackTree<int, std::less<>>, AVLTree<int, std::less<>>) {
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

using namespace exam::lists;
TEST_CASE("DLL") {
    std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor from init list") {
        auto list = DoubleLinkedList<int>({1,4,103,2,24});
        auto iterator = list.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    SUBCASE("Constructor from init list") {
        auto list = DoubleLinkedList<int>(elems.begin(), elems.end());
        auto iterator = list.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    auto list = DoubleLinkedList<int>(elems.begin(), elems.end());

    SUBCASE("Copy constructor") {
        auto copyList = DoubleLinkedList<int>(list);
        auto iterator = copyList.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    SUBCASE("Operator = ") {
        auto copyList = DoubleLinkedList<int>(elems.begin(), (elems.begin()+2));
        copyList = list;
        auto iterator = copyList.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    SUBCASE("Insert in the begin") {
        list.insert(25, list.begin());

        auto iterator = list.begin();
        REQUIRE(list.size() == 6);
        REQUIRE(*iterator == 25);
        REQUIRE(*(++iterator) == 1);
        REQUIRE(*(--list.end()) == 24);
    }

    SUBCASE("Insert in the middle") {
        auto iterator = list.begin();
        for (int i = 0; i < 3; ++i) {
            ++iterator;
        }
        list.insert(25, iterator);

        REQUIRE(list.size() == 6);
        REQUIRE(*iterator == 2);
        REQUIRE(*(--iterator) == 25);
        REQUIRE(*(--iterator) == 103);
    }

    SUBCASE("Erase") {
        list.erase(103);
        list.erase(1);
        list.erase(24);
        list.erase(27);

        REQUIRE(list.size() == 2);
        REQUIRE(*(list.begin()) == 4);
        REQUIRE(*(++list.begin()) == 2);
    }
}