
#include <iostream>

int main () {

    using namespace exam::hashtable;

    StaticCoalestedHashTable<int, 5> table = {3, 9, 45, 14, 8};


    for (const auto& elem : table) {
        std::cout << elem << ' ';
    }

    return 0;
}