#pragma once

#include "../../src/LinkedLists/Iterators/CyclicForwardIterator.hpp"

namespace exam::lists {

    template <typename T>
    class CyclicLinkedList {
        struct SLLNode {
            T _data;
            SLLNode* _next = nullptr;

            SLLNode(const T& data) : _data(data) {}
        };

        SLLNode* _head = nullptr;
        SLLNode* _tail = nullptr;
        size_t _size = 0;

    public:
        using Iterator = detail::CyclicForwardIterator<SLLNode*, T, CyclicLinkedList>;

        using value_type = T;

        explicit CyclicLinkedList() = default;

        CyclicLinkedList(std::initializer_list<T> elems);

        template <typename Iter>
        CyclicLinkedList(Iter begin, Iter end);

        Iterator begin();

        Iterator end();

        void insert(const T& data, Iterator& iterator);
        void insert(const T& data, Iterator&& iterator);

        void erase(const T& data);

        [[nodiscard]]
        size_t size();

        ~CyclicLinkedList();
    };

}

#include "../../src/LinkedLists/Cyclic.tpp"