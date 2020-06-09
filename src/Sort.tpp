#pragma once

#include "../include/Sorts/Quick.hpp"
#include "../include/Sorts/Merge.hpp"
#include "../include/Sorts/Insertion.hpp"
#include "../include/Sorts/Selection.hpp"
#include "../include/Sorts/Radix.hpp"
#include "../include/Sorts/Heap.hpp"
#include "../include/Sorts/Bucket.hpp"
#include "../include/Sorts/BSTSort.hpp"


namespace exam::sort {

    template <typename T>
    auto Sorter<T>::sort_type(const Sorter::SortType type) noexcept -> Sorter&
    {
        _sort_type = type;
        return *this;
    }

    template <typename T>
    auto Sorter<T>::policy(const ExecutionPolicy policy) noexcept -> Sorter&
    {
        _policy = policy;
        return *this;
    }

    template <typename T>
    auto Sorter<T>::comparator(const std::function<bool(const T&, const T&)> &comp) noexcept -> Sorter&
    {
        _comp = comp;
        return *this;
    }

    template <typename T>
    template <typename Iter>
    void Sorter<T>::sort(Iter begin, Iter end) {

        switch (_sort_type) {

            case SortType::Quick:
                quick_sort(begin, end, _policy, _comp);
                break;
            case SortType::Merge:
                merge_sort(begin, end, _policy, _comp);
                break;
            case SortType::Bucket:
                bucket_sort(begin, end, _policy);
                break;
            case SortType::Radix:
                radix_sort(begin, end, _policy);
                break;
            case SortType::Selection:
                selection_sort(begin, end, _comp);
                break;

            case SortType::Insertion:
                insertion_sort(begin, end, _comp);
                break;
            case SortType::Heap:
                heap_sort(begin, end, _comp);
                break;
            case SortType::BinarySearchTree:
                bst_sort(begin, end, _comp);
                break;
        }
    }
}
