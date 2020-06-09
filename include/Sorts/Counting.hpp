#pragma once

#include "../../src/Sorts/CountingImpl.hpp"

#include <functional>

namespace exam::sort {

    template <typename Iter>
    inline void counting_sort (Iter begin, Iter end) {
        static_assert(std::is_integral_v<typename Iter::value_type>);
        detail::default_counting(begin, end);
    }
}
