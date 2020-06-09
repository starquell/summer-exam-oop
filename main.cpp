#include <iostream>

#include "include/AllExam.hpp"

#include <list>

int main () {


     auto vec = exam::random<std::vector<int>>(100, 0, 100);

     exam::sort::Sorter<int>{}.sort_type(exam::sort::Sorter<int>::SortType::BinarySearchTree)
                              .comparator(std::less<int>{})
                              .sort(vec.begin(), vec.end());

     for (const auto& i : vec) {
         std::cout << i << ' ';
     }
     std::cout << std::endl;

    return 0;
}