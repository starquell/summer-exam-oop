#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../3rdparty/doctest/doctest.h"
#include "../include/Trees/RedBlack.hpp"
#include "../include/Trees/Splay.hpp"
#include "../include/Trees/AVL.hpp"
#include "../include/LinkedLists/DoubleLinked.hpp"
//#include "../include/LinkedLists/Cyclic.hpp"

using namespace exam::tree;

TEST_CASE("Red Black Tree") {

    std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor's from iterators test") {
        auto tree = RedBlackTree<int, std::less<>> (elems.begin(), elems.end());

        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 2);
        REQUIRE(*(tree.begin() + 2) == 4);
        REQUIRE(*(tree.begin() + 3) == 24);
        REQUIRE(*(tree.begin() + 4) == 103);
    }
    auto tree = RedBlackTree<int, std::less<>> (elems.begin(), elems.end());

    SUBCASE("Insert") {
        tree.insert(100);
        REQUIRE(tree.search(100));
    }

    SUBCASE("Erase") {
        REQUIRE(tree.search(elems[0]));
        tree.erase(elems[0]);

        REQUIRE_FALSE(tree.search(elems[0]));
    }

    SUBCASE("Multi insertion and deletion") {
        tree.insert(15);
        tree.insert(203);
        tree.insert(2);
        tree.erase(4);
        tree.erase(15);
        tree.erase(45);
        tree.insert(18);
        tree.erase(2);
        tree.insert(46);

        REQUIRE(tree.size() == 6);
        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 18);
        REQUIRE(*(tree.begin() + 2) == 24);
        REQUIRE(*(tree.begin() + 3) == 46);
        REQUIRE(*(tree.begin() + 4) == 103);
        REQUIRE(*(tree.begin() + 5) == 203);
    }
}

TEST_CASE("Splay Tree") {

    std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor's from iterators test") {
        auto tree = SplayTree<int, std::less<>> (elems.begin(), elems.end());

        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 2);
        REQUIRE(*(tree.begin() + 2) == 4);
        REQUIRE(*(tree.begin() + 3) == 24);
        REQUIRE(*(tree.begin() + 4) == 103);
    }
    auto tree = SplayTree<int, std::less<>> (elems.begin(), elems.end());

    SUBCASE("Insert") {
        tree.insert(100);
        REQUIRE(tree.search(100));
    }

    SUBCASE("Erase") {
        REQUIRE(tree.search(elems[0]));
        tree.erase(elems[0]);

        REQUIRE_FALSE(tree.search(elems[0]));
    }

    SUBCASE("Multi insertion and deletion") {
        tree.insert(15);
        tree.insert(203);
        tree.insert(2);
        tree.erase(4);
        tree.erase(15);
        tree.erase(45);
        tree.insert(18);
        tree.erase(2);
        tree.insert(46);

        REQUIRE(tree.size() == 6);
        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 18);
        REQUIRE(*(tree.begin() + 2) == 24);
        REQUIRE(*(tree.begin() + 3) == 46);
        REQUIRE(*(tree.begin() + 4) == 103);
        REQUIRE(*(tree.begin() + 5) == 203);
    }
}

TEST_CASE("AVL Tree") {
    std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor's from iterators test") {
        auto tree = AVLTree<int, std::less<>> (elems.begin(), elems.end());

        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 2);
        REQUIRE(*(tree.begin() + 2) == 4);
        REQUIRE(*(tree.begin() + 3) == 24);
        REQUIRE(*(tree.begin() + 4) == 103);
    }
    auto tree = AVLTree<int, std::less<>> (elems.begin(), elems.end());

    SUBCASE("Insert") {
        tree.insert(100);
        REQUIRE(tree.search(100));
    }

    SUBCASE("Erase") {
        REQUIRE(tree.search(elems[0]));
        tree.erase(elems[0]);
        REQUIRE_FALSE(tree.search(elems[0]));

        REQUIRE(*tree.begin() == 2);
        REQUIRE(*(tree.begin() + 1) == 4);
        REQUIRE(*(tree.begin() + 2) == 24);
        REQUIRE(*(tree.begin() + 3) == 103);
    }

    SUBCASE("Multi insertion and deletion") {
        tree.insert(15);
        tree.insert(203);
        tree.insert(2);
        tree.erase(4);
        tree.erase(15);
        tree.erase(45);
        tree.insert(18);
        tree.erase(2);
        tree.insert(46);

        REQUIRE(tree.size() == 6);
        REQUIRE(*tree.begin() == 1);
        REQUIRE(*(tree.begin() + 1) == 18);
        REQUIRE(*(tree.begin() + 2) == 24);
        REQUIRE(*(tree.begin() + 3) == 46);
        REQUIRE(*(tree.begin() + 4) == 103);
        REQUIRE(*(tree.begin() + 5) == 203);
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