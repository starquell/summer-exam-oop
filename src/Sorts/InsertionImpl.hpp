#pragma once

#include <algorithm>

namespace exam::sort::detail {

    template <typename Iter, typename Comp>
    void default_insertion(Iter beg, Iter end, Comp comp) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        using std::swap;

        auto currIntervalBegin = beg;

        ++currIntervalBegin;
        do {
            auto prev = currIntervalBegin;
            --prev;
            auto value = *currIntervalBegin;
            while (prev >= beg && !comp(*prev, value)) {
                auto valueForSwap = *prev;
                swap(*(++prev), valueForSwap);
                --prev;
                --prev;
            }
            swap(*(++prev), value);
            ++currIntervalBegin;
        } while (currIntervalBegin != end);
    }
}
