#pragma once

#include "../include/Sorts/Quick.hpp"
#include "../include/Sorts/Bucket.hpp"
#include "../include/Sorts/Counting.hpp"
#include "../include/Sorts/Radix.hpp"
#include "../include/Sorts/Merge.hpp"
#include "../include/Sorts/Selection.hpp"
#include "../include/Sorts/Insertion.hpp"
#include "../include/Random.hpp"

#include <algorithm>

using namespace exam::sort;

template <typename Func, typename Comp = std::less<>>
void test_sort (Func&& func,
                ExecutionPolicy policy = ExecutionPolicy::Default,
                Comp&& comp = Comp{}) {

    for (auto i = 10; i <= 100000; i *= 20) {
        auto random_vec = exam::random<std::vector<int>>(i, 0, i);

        func(random_vec.begin(), random_vec.end(), comp);

        REQUIRE (std::is_sorted(random_vec.begin(), random_vec.end()));
    }
}

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

TEST_CASE ("Merge sort") {

            SUBCASE("Single thread") {
                SUBCASE("Less comparator") {
            for (auto i = 10; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                merge_sort(vec.begin(), vec.end());
                        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

                SUBCASE("Greater comparator") {
            for (auto i = 100; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                merge_sort(vec.begin(), vec.end(), std::greater{});
                        REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }

            SUBCASE ("Parallel") {
                SUBCASE("Less comparator") {
            for (auto i = 10000; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                merge_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
                        REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

                SUBCASE("Greater comparator") {
            for (auto i = 10000; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<int>> (i, 0, i);

                merge_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel, std::greater{});
                        REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }
}

TEST_CASE ("Bucket sort") {

    SUBCASE("Single thread") {
        SUBCASE("Less comparator") {
            for (auto i = 10; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end());
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("Greater comparator") {
            for (auto i = 10; i <= 100000; i *= 100) {
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
            for (auto i = 10; i <= 100000; i *= 10) {
                auto vec = exam::random<std::vector<float>> (i, 0, 1);

                bucket_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel, std::greater{});
                REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
            }
        }
    }
}

TEST_CASE ("Counting sort") {

    SUBCASE("Without negative numbers") {
        for (auto i = 10; i <= 100000; i *= 100) {
            auto vec = exam::random<std::vector<int>>(i, 0, i);

            counting_sort(vec.begin(), vec.end());
            REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        }
    }

    SUBCASE("With negative numbers") {
        for (auto i = 10; i <= 100000; i *= 100) {
            auto vec = exam::random<std::vector<int>>(i, -i, i);

            counting_sort(vec.begin(), vec.end());
            REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        }
    }
}

TEST_CASE ("Radix sort") {

    SUBCASE("Single thread") {
        SUBCASE("Without negative numbers") {
            for (auto i = 10; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<int>>(i, 0, i);

                radix_sort(vec.begin(), vec.end());
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("With negative numbers") {
            for (auto i = 10; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<int>>(i, -i, i);

                radix_sort(vec.begin(), vec.end());
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }
    }
    SUBCASE("Parallel") {
        SUBCASE("Without negative numbers") {
            for (auto i = 10; i <= 100000; i *= 100) {
                auto vec = exam::random<std::vector<int>>(i, 0, i);

                radix_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }

        SUBCASE("With negative numbers") {
            for (auto i = 10; i <= 1000000; i *= 100) {
                auto vec = exam::random<std::vector<int>>(i, -i, i);

                radix_sort(vec.begin(), vec.end(), ExecutionPolicy::Parallel);
                REQUIRE(std::is_sorted(vec.begin(), vec.end()));
            }
        }
    }
}

TEST_CASE ("Selection sort") {

    SUBCASE("Less comparator") {
        for (auto i = 10; i <= 10000; i *= 10) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            selection_sort(vec.begin(), vec.end());
            REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        }
    }

    SUBCASE("Greater comparator") {
        for (auto i = 10; i <= 10000; i *= 10) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            selection_sort(vec.begin(), vec.end(), std::greater{});
            REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
        }
    }

}

TEST_CASE ("Insertion sort") {

    SUBCASE("Less comparator") {
        for (auto i = 10; i <= 10000; i *= 10) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            insertion_sort(vec.begin(), vec.end());
            REQUIRE(std::is_sorted(vec.begin(), vec.end()));
        }
    }

    SUBCASE("Greater comparator") {
        for (auto i = 10; i <= 10000; i *= 10) {
            auto vec = exam::random<std::vector<int>> (i, 0, i);

            insertion_sort(vec.begin(), vec.end(), std::greater{});
            REQUIRE(std::is_sorted(vec.begin(), vec.end(), std::greater{}));
        }
    }

}
