#pragma once

#include "../../src/Sorts/SelectionImpl.hpp"
#include "MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    inline void selection_sort (Iter begin, Iter end, Comp comp = std::less<>{}) {
        detail::default_selection(begin, end, comp);
    }

}