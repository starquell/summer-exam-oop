#include <iostream>

#include "include/AllExam.hpp"

#include <list>

int main () {

     using namespace exam::hashtable;

     auto table =  StaticCoalestedHashTable<int, 10>{};

     table.insert(2);
     table.insert(32);
     table.insert(42);
     table.insert(52);
     table.insert(62);
     table.insert(72);
     table.insert(82);
     table.insert(92);
     table.insert(22);
     table.insert(12);

    table.erase(2);
    table.erase(32);
    table.erase(42);
    table.erase(52);
    table.erase(62);
    table.erase(72);
    table.erase(82);
    table.erase(92);
    table.erase(22);
    table.erase(12);



    for (auto i : table) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;

    return 0;
}