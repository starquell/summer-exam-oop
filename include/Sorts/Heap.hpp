#pragma once

#include "MutualDefs.hpp"

#include <algorithm>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    void heap_sort (Iter begin, Iter end, Comp comp = Comp{}) {

        std::make_heap(begin, end, comp);
        while (begin != end) {
            std::pop_heap(begin, end, comp);
            --end;
        }
    }
}