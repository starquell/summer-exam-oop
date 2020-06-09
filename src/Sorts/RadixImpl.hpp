#pragma once

#include <algorithm>
#include <future>

#include "CountingImpl.hpp"

namespace exam::sort::detail {

    template <typename Iter>
    void default_radix(Iter beg, Iter end) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        std::vector<typename Iter::value_type> positive, negative;

        auto curr = beg;
        while (curr != end) {
            auto value = *curr;
            if (value >= 0) {
                positive.push_back(value);
            } else {
                negative.push_back(value * (-1));
            }
            ++curr;
        }

        auto maxPos = positive.empty() ? 0 : *max_element(positive.begin(), positive.end());
        auto maxNeg = negative.empty() ? 0 : *max_element(negative.begin(), negative.end());

        for (int exp = 1; maxPos / exp > 0; exp *= 10) {
            counting_digit(positive.begin(), positive.end(), exp);
        }
        for (int exp = 1; maxNeg / exp > 0; exp *= 10) {
            counting_digit(negative.begin(), negative.end(), exp);
        }

        using std::swap;

        for (int i = negative.size() - 1; i >= 0; --i) {
            auto value = negative[i] * (-1);
            swap(value, *beg);
            ++beg;
        }

        for (auto item : positive) {
            swap(item, *beg);
            ++beg;
        }
    }

    template <typename Iter>
    void parallel_radix(Iter beg, Iter end) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        std::vector<typename Iter::value_type> positive, negative;

        auto curr = beg;
        while (curr != end) {
            auto value = *curr;
            if (value >= 0) {
                positive.push_back(value);
            } else {
                negative.push_back(value * (-1));
            }
            ++curr;
        }

        auto positiveResult = std::async(std::launch::async,
                [&positive] () {
                    auto maxPos = positive.empty() ? 0 : *max_element(positive.begin(), positive.end());
                    for (int exp = 1; maxPos / exp > 0; exp *= 10) {
                        counting_digit(positive.begin(), positive.end(), exp);
                    }
            });

        auto maxNeg = negative.empty() ? 0 : *max_element(negative.begin(), negative.end());
        for (int exp = 1; maxNeg / exp > 0; exp *= 10) {
            counting_digit(negative.begin(), negative.end(), exp);
        }

        using std::swap;

        for (int i = negative.size() - 1; i >= 0; --i) {
            auto value = negative[i] * (-1);
            swap(value, *beg);
            ++beg;
        }

        positiveResult.wait();
        for (auto item : positive) {
            swap(item, *beg);
            ++beg;
        }
    }
}
