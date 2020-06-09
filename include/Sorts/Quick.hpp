#pragma once

#include "../../src/Sorts/QuickImpl.hpp"
#include "MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    inline void quick_sort (Iter begin, Iter end, Comp comp = std::less<>{})
    {
        quick_sort(begin, end, ExecutionPolicy::Default, comp);
    }



    template <typename Iter, typename Comp = std::less<>>
    inline void quick_sort (Iter begin,
                            Iter end,
                            ExecutionPolicy policy,
                            Comp comp = std::less<>{})
    {
        if (policy == ExecutionPolicy::Default) {
            detail::default_quick(begin, end, comp);
        }
        else {
            detail::parallel_quick(begin, end, comp);
        }
    }
}