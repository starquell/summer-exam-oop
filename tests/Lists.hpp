#pragma once

#include "../include/LinkedLists/DoubleLinked.hpp"
#include "../include/LinkedLists/Cyclic.hpp"
#include "../include/LinkedLists/SinglyLinked.hpp"

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

    SUBCASE("Empty list constructor") {
        auto list = DoubleLinkedList<int>();

        REQUIRE(list.size() == 0);
        list.insert(5, list.begin());
        REQUIRE(list.size() == 1);
        REQUIRE(*(list.begin()) == 5);
        list.erase(5);
        REQUIRE(list.size() == 0);
        list.insert(5, list.begin());
        REQUIRE(list.size() == 1);
        REQUIRE(*(list.begin()) == 5);
    }

    auto list = DoubleLinkedList<int>(elems.begin(), elems.end());

    SUBCASE("Copy constructor") {
        auto copyList = DoubleLinkedList<int>(list);

        REQUIRE(list.size() == 5);
        std::equal (copyList.begin(), copyList.end(), elems.begin());
    }

    SUBCASE("Operator = ") {
        auto copyList = DoubleLinkedList<int>(elems.begin(), (elems.begin()+2));
        copyList = list;

        REQUIRE(list.size() == 5);
        std::equal (copyList.begin(), copyList.end(), elems.begin());
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

    SUBCASE("Insert in the end") {
        list.insert(25, list.end());

        auto iterator = list.end();
        REQUIRE(list.size() == 6);
        REQUIRE(*(--iterator) == 25);
        REQUIRE(*(--iterator) == 24);
        REQUIRE(*list.begin() == 1);
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

SCENARIO_TEMPLATE("Singly linked lists", List,
                  SinglyLinkedList<int>,
                  CyclicLinkedList<int>)
{
    std::array elems = {1, 4, 103, 2, 24};

    SUBCASE("Constructor from init list") {
        auto list = List({1,4,103,2,24});
        auto iterator = list.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    SUBCASE("Constructor from init list") {
        auto list = List(elems.begin(), elems.end());
        auto iterator = list.begin();

        REQUIRE(list.size() == 5);
        REQUIRE(*(iterator++) == 1);
        REQUIRE(*(iterator++) == 4);
        REQUIRE(*(iterator++) == 103);
        REQUIRE(*(iterator++)== 2);
        REQUIRE(*(iterator++) == 24);
    }

    SUBCASE("Empty list constructor") {
        auto list = List();

        REQUIRE(list.size() == 0);
        list.insert(5, list.begin());
        REQUIRE(list.size() == 1);
        REQUIRE(*(list.begin()) == 5);
        list.erase(5);
        REQUIRE(list.size() == 0);
        list.insert(5, list.begin());
        REQUIRE(list.size() == 1);
        REQUIRE(*(list.begin()) == 5);
    }

    auto list = List(elems.begin(), elems.end());

    SUBCASE("Copy constructor") {
        auto copyList = List(list);

        REQUIRE(list.size() == 5);
        std::equal(copyList.begin(), copyList.end(), elems.begin());
    }

    SUBCASE("Operator = ") {
        auto copyList = List(elems.begin(), (elems.begin()+2));
        copyList = list;

        REQUIRE(list.size() == 5);
        std::equal(copyList.begin(), copyList.end(), elems.begin());
    }

    SUBCASE("Insert in the begin") {
        list.insert(25, list.begin());

        auto iterator = list.begin();
        REQUIRE(list.size() == 6);
        REQUIRE(*iterator == 25);
        REQUIRE(*(++iterator) == 1);
        for (int i = 0; i < elems.size() - 1; i++) {
            ++iterator;
        }
        REQUIRE(*iterator == 24);
    }

    SUBCASE("Insert in the middle") {
        auto iterator = list.begin();
        for (int i = 0; i < 3; ++i) {
            ++iterator;
        }
        list.insert(25, iterator);

        iterator = list.begin();
        REQUIRE(list.size() == 6);
        REQUIRE(*iterator == 1);
        for (int i = 0; i < 2; ++i) {
            ++iterator;
        }
        REQUIRE(*iterator == 103);
        REQUIRE(*(++iterator) == 25);
    }

    SUBCASE("Insert in the end") {
        list.insert(25, list.end());

        REQUIRE(list.size() == 6);
        REQUIRE(*list.end() == 25);
        auto iterator = list.begin();
        REQUIRE(*iterator == 1);
        for (int i = 0; i < elems.size() - 1; ++i) {
            ++iterator;
        }
        REQUIRE(*iterator == 24);
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

TEST_CASE("Cyclic list") {
    SUBCASE("Check cyclic") {
        auto list = CyclicLinkedList<int>({1,4,103,2,24});
        auto iterator = list.begin();

            REQUIRE(list.size() == 5);
            for (int i = 0; i < 2; i++) {
                REQUIRE(*(iterator++) == 1);
                REQUIRE(*(iterator++) == 4);
                REQUIRE(*(iterator++) == 103);
                REQUIRE(*(iterator++) == 2);
                REQUIRE(*(iterator++) == 24);
            }
    }
}