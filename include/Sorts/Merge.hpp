#pragma once

#include "../src/Sorts/MergeImpl.hpp"

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    inline void merge_sort (Iter begin, Iter end, Comp comp = std::less<>{})
    {
        merge_sort(begin, end, ExecutionPolicy::Default, comp);
    }


    template <typename Iter, typename Comp = std::less<>>
    inline void merge_sort (Iter begin,
                            Iter end,
                            ExecutionPolicy policy,
                            Comp comp = std::less<>{})
    {
        if (policy == ExecutionPolicy::Default) {
            detail::default_merge_sort(begin, end, comp);
        }
        else {
            detail::parallel_merge_sort(begin, end, comp);
        }
    }

}