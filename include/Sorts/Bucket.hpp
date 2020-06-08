#pragma once

#include "../../src/Sorts/BucketImpl.hpp"
#include "MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter, typename Comp = std::less<>>
    inline void bucket_sort (Iter begin, Iter end, Comp comp = std::less<>{}) {
        bucket_sort(begin, end, ExecutionPolicy::Default, 0, comp);
    }


    template <typename Iter, typename Comp = std::less<>>
    inline void bucket_sort (Iter begin,
                            Iter end,
                            ExecutionPolicy policy,
                            Comp comp = std::less<>{}) {
        bucket_sort(begin, end, policy, 0, comp);
    }

    template <typename Iter, typename Comp = std::less<>>
    inline void bucket_sort (Iter begin, Iter end,
                             size_t bucketsNumber,
                             Comp comp = std::less<>{}) {
        bucket_sort(begin, end, ExecutionPolicy::Default, bucketsNumber, comp);
    }

    template <typename Iter, typename Comp = std::less<>>
    inline void bucket_sort (Iter begin, Iter end,
                            ExecutionPolicy policy,
                            size_t bucketsNumber,
                            Comp comp = std::less<>{}) {
        if (policy == ExecutionPolicy::Default) {
            detail::default_bucket(begin, end, bucketsNumber, comp);
        }
        else {
            detail::parallel_bucket(begin, end, bucketsNumber, comp);
        }
    }
}