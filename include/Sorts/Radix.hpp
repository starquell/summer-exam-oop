#pragma once

#include "../../src/Sorts/RadixImpl.hpp"
#include "MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter>
    inline void radix_sort (Iter begin, Iter end) {
        radix_sort(begin, end, ExecutionPolicy::Default);
    }

    template <typename Iter>
    inline void radix_sort (Iter begin, Iter end, ExecutionPolicy policy) {
        static_assert(std::is_integral_v<typename Iter::value_type>);
        if (policy == ExecutionPolicy::Default) {
            detail::default_radix(begin, end);
        } else {
            detail::parallel_radix(begin, end);
        }
    }

}