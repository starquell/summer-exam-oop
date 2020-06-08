#pragma once

#include <algorithm>

namespace exam::sort::detail {

    template <typename Iter>
    void default_counting(Iter beg, Iter end) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        auto max = *max_element(beg, end);
        auto min = *min_element(beg, end);
        size_t range = max - min + 1;

        std::vector<size_t> countVec(range, 0);
        std::vector<typename Iter::value_type> sorted(distance);
        auto curr = beg;
        while (curr != end) {
            ++countVec[*curr - min];
            ++curr;
        }

        for (int i = 1; i < countVec.size(); ++i) {
            countVec[i] += countVec[i - 1];
        }

        curr = beg;
        while (curr != end) {
            auto currValue = *curr;
            sorted[countVec[currValue - min] - 1] = currValue;
            --countVec[currValue - min];
            ++curr;
        }

        using std::swap;

        for (auto item : sorted) {
            swap(item, *beg);
            ++beg;
        }
    }

    template <typename Iter>
    void counting_digit(Iter beg, Iter end, int exp) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        std::vector<size_t> countVec(10, 0);
        std::vector<typename Iter::value_type> sorted(distance);
        auto curr = beg;
        while (curr != end) {
            ++countVec[(*curr)/exp % 10];
            ++curr;
        }

        for (int i = 1; i < countVec.size(); ++i) {
            countVec[i] += countVec[i - 1];
        }

        curr = end;
        while (curr != beg) {
            --curr;
            auto currValue = *curr;
            sorted[countVec[(currValue / exp) % 10] - 1] = currValue;
            --countVec[(currValue / exp) % 10];
        }

        using std::swap;

        for (auto item : sorted) {
            swap(item, *beg);
            ++beg;
        }
    }
}