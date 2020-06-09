#pragma once

#include "Sorts/MutualDefs.hpp"

#include <functional>

namespace exam::sort {

    /**
     *  @brief Class for sorting value ranges
     */
    template <typename T>
    class Sorter {
    public:

        enum class SortType {
            Quick,
            Merge,
            Selection,
            Insertion,
            Counting,
            Radix,
            Bucket,
            Heap,
            BinarySearchTree
        };

        auto sort_type (SortType type) noexcept -> Sorter&;

        auto policy (ExecutionPolicy policy) noexcept -> Sorter&;

        auto comparator (const std::function<bool(const T&, const T&)>& comp) noexcept -> Sorter&;

        template <typename Iter>
        void sort (Iter begin, Iter end);

    private:
        SortType _sort_type = SortType::Quick;
        ExecutionPolicy _policy = ExecutionPolicy::Default;
        std::function<bool(const T&, const T&)> _comp = std::less<T>{};
    };
}

#include "../src/Sort.tpp"