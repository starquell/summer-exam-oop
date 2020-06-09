#pragma once

#include <algorithm>
#include <cassert>
#include<cmath>
#include <future>
#include "../../3rdparty/thread_pool/ThreadPool.h"

namespace exam::sort::detail {

    template <typename Iter, typename Comp>
    void default_bucket(Iter beg, Iter end, size_t bucketsNumber, Comp comp) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        if (bucketsNumber <= 1) {
            bucketsNumber = sqrt(distance);
        }

        std::vector<std::vector<typename Iter::value_type>> buckets(bucketsNumber);

        Iter curr = beg;
        while (curr != end) {
            size_t index = (bucketsNumber * (*curr));
            buckets[index % bucketsNumber].push_back(*curr);
            curr++;
        }

        for (int i = 0; i < bucketsNumber; i++) {
            std::sort(buckets[i].begin(), buckets[i].end(), comp);
        }

        std::sort(buckets.begin(), buckets.end(),
                [&] (const auto& lhs_vec, const auto& rhs_vec) {
                    return comp(lhs_vec[0], rhs_vec[0]);
                });

        using std::swap;

        for (int i = 0; i < bucketsNumber; i++) {
            auto bucketIterator = buckets[i].begin();
            while (bucketIterator != buckets[i].end()) {
                swap(*bucketIterator, *beg);
                bucketIterator++;
                beg++;
            }
        }
    }


    template <typename Iter, typename Comp>
    void parallel_bucket(Iter beg, Iter end, size_t bucketsNumber, Comp comp) {

        const auto distance = std::distance(beg, end);

        if (distance < 2) {
            return;
        }

        if (bucketsNumber <= 1) {
            bucketsNumber = sqrt(distance);
        }

        std::vector<std::vector<typename Iter::value_type>> buckets(bucketsNumber);

        Iter curr = beg;
        while (curr != end) {
            size_t index = (bucketsNumber * (*curr));
            buckets[index % bucketsNumber].push_back(*curr);
            curr++;
        }

        const auto HW_concurrency = std::thread::hardware_concurrency();

        ThreadPool pool(HW_concurrency / 2);
        std::vector<std::future<void>> results;

        for (int i = 0; i < bucketsNumber; i++) {
            results.push_back(pool.enqueue([&buckets, comp, i]() {
                std::sort(buckets[i].begin(), buckets[i].end(), comp);
            }));
        }

        for (auto && result : results) {
            result.get();
        }

        std::sort(buckets.begin(), buckets.end(),
                  [&] (const auto& lhs_vec, const auto& rhs_vec) {
                      return comp(lhs_vec[0], rhs_vec[0]);
                  });

        using std::swap;

        for (int i = 0; i < bucketsNumber; i++) {
            auto bucketIterator = buckets[i].begin();
            while (bucketIterator != buckets[i].end()) {
                swap(*bucketIterator, *beg);
                bucketIterator++;
                beg++;
            }
        }
    }
}
