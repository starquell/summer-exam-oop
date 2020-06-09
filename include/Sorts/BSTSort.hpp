#pragma once

#include "MutualDefs.hpp"

#include <set>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    void bst_sort (Iter begin, Iter end, Comp comp = Comp{}) {

        std::multiset <typename Iter::value_type, Comp> bst(comp);

        for (auto it = begin; it != end; ++it) {
            bst.insert(*it);
        }
        std::copy (bst.begin(), bst.end(), begin);
    }
}