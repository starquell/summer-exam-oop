#pragma once

namespace exam::sort::detail {

    template <typename Iter, typename Comp>
    void default_merge_sort (Iter begin, Iter end, Comp comp) {

        const auto distance = std::distance(begin, end);
        if (distance < 2) {
            return;
        }
        auto mid = begin;
        std::advance(mid, distance / 2);
        default_merge_sort (begin, mid, comp);
        default_merge_sort (mid, end, comp);
        std::inplace_merge (begin, mid, end, comp);
    }

    template <typename Iter, typename Comp>
    void parallel_merge_sort (Iter begin, Iter end, Comp comp) {

        const auto distance = std::distance(begin, end);

        if (distance <= PARALLELING_POINT) {
            default_merge_sort(begin, end, comp);
            return;
        }
        if (distance < 2) {
            return;
        }
        auto mid = begin;
        std::advance(mid, distance / 2);

        std::future<void> result;
        if (std::distance(begin, mid) > PARALLELING_POINT) {
            result = std::async(std::launch::async, parallel_merge_sort<Iter, Comp>, begin, mid, comp);
        }
        else {
            parallel_merge_sort(begin, mid, comp);
        }
        parallel_merge_sort (mid, end, comp);
        if (result.valid()) {
            result.wait();
        }
        std::inplace_merge (begin, mid, end, comp);
    }
}