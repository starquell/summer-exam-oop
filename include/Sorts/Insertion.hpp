#pragma once

#include "../../src/Sorts/InsertionImpl.hpp"
#include "MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    inline void insertion_sort (Iter begin, Iter end, Comp comp = std::less<>{}) {
        detail::default_insertion(begin, end, comp);
    }

}