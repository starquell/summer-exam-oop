#pragma once

#include <execution>

namespace exam::sort::detail {

    template <typename Iter>
    void default_merge_sort (Iter begin, Iter end) {

        const auto distance = std::distance(begin, end);
        if (distance < 2) {
            return;
        }
        const auto mid = begin + distance / 2 + 1;
        default_merge_sort (begin, mid);
        default_merge_sort (mid, end);
        std::inplace_merge (begin, mid, end);
    }

    template <typename Iter>
    void parallel_merge_sort (Iter begin, Iter end) {

        const auto distance = std::distance(begin, end);
        if (distance < 2) {
            return;
        }
        const auto mid = begin + distance / 2 + 1;

        if (std::distance(begin, mid) > PARALLELING_POINT) {
            std::async(std::launch::async, parallel_merge_sort, begin, mid);
        }
        else {
            parallel_merge_sort(begin, mid);
        }
        parallel_merge_sort (mid, end);
        std::inplace_merge (std::execution::par_unseq, begin, mid, end);
    }
}