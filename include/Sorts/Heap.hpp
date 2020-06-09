#pragma once

#include <algorithm>

namespace exam::sort {

    template <typename Iter, typename Comp>
    void heap_sort (Iter begin, Iter end, Comp comp) {

        std::make_heap(begin, end, comp);
        while (begin != end) {
            std::pop_heap(begin, end, comp);
            --end;
        }
    }
}