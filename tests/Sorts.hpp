#pragma once

#include "../include/Sorts/Quick.hpp"
#include "../include/Sorts/Bucket.hpp"
#include "../include/Random.hpp"

#include "../include/Sorts/Merge.hpp"

#include <algorithm>

using namespace exam::sort;


TEST_CASE ("Quick sort") {

    SUBCASE("Single thread") {
        SUBCASE("Less comparator") {
        for (auto i = 10; i <= 1000000; i *= 100) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            quick_sort(vec.begin(), vec.end());
            REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("Greater comparator") {
        for (auto i = 100; i <= 1000000; i *= 100) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            quick_sort(vec.begin(), vec.end(), std::greater{});
            REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }

    SUBCASE ("Parallel") {
        SUBCASE("Less comparator") {
            for (auto i = 10000; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                quick_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("Greater comparator") {
            for (auto i = 10000; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                quick_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel, std::greater{});
                REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }
}

TEST_CASE ("Bucket sort") {

    SUBCASE("Single thread") {
        SUBCASE("Less comparator") {
            for (auto i = 10; i <= 1000000; i *= 100) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end());
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("Greater comparator") {
            for (auto i = 100; i <= 1000000; i *= 100) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end(), std::greater{});
                REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }

    SUBCASE ("Parallel") {
        SUBCASE("Less comparator") {
            for (auto i = 10; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("Greater comparator") {
            for (auto i = 10000; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel, std::greater{});
                REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }
    const auto test_sort = [] (const auto& func) {
        for (auto i = 10; i <= 100000; i *= 20) {
            auto random_vec = exam::random<std::vector<int>>(i);

            func(random_vec.begin(), random_vec.end());

            REQUIRE (std::is_sorted(random_vec.begin(), random_vec.end()));
        }
    };

}