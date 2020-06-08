#pragma once

#include <algorithm>

namespace exam::sort::detail {

    template <typename Iter, typename Comp>
    void default_selection(Iter beg, Iter end, Comp comp) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        using std::swap;

        auto currIntervalBegin = beg;
        do {
            auto min = currIntervalBegin;
            auto currInInterval = currIntervalBegin;
            ++currInInterval;
            for (; currInInterval != end; ++currInInterval) {
                if (comp(*currInInterval, *min)) {
                    min = currInInterval;
                }
            }
            swap(*currIntervalBegin, *min);
            currIntervalBegin++;
        } while (currIntervalBegin != end);
    }
}
