#include <iostream>

#include "include/AllExam.hpp"

#include <list>

int main () {

    std::cout << exam::random<int>() << std::endl;
    std::cout << exam::random<int>(34, 64) << std::endl;
    std::cout << exam::random<char>('a', 'o') << std::endl;

    std::cout << exam::random<std::string>(4) << std::endl;

    for (auto i : exam::random<std::vector<int>>(10)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (const auto& i : exam::random<std::array<std::string, 5>>(10)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (const auto& i : exam::random<std::list<double>>(10)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (const auto& i : exam::random<exam::tree::RedBlackTree<int>>(7, -100, 100)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    for (const auto& i : exam::random<exam::hashtable::StaticCoalestedHashTable<int, 5>>(-10, 10)) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}