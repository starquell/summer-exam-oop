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
        using iterator = detail::CyclicForwardIterator<SLLNode*, T, CyclicLinkedList>;

        using value_type = T;

        explicit CyclicLinkedList() = default;

        CyclicLinkedList(std::initializer_list<T> elems);

        template <typename Iter>
        CyclicLinkedList(Iter begin, Iter end);

        CyclicLinkedList(const CyclicLinkedList<T>& other);

        CyclicLinkedList& operator= (const CyclicLinkedList& other);


        iterator begin() const;

        iterator end() const;

        void insert(const T& data, iterator& iterator);
        void insert(const T& data, iterator&& iterator);

        void erase(const T& data);

        [[nodiscard]]
        size_t size() const;

        ~CyclicLinkedList();
    };

}

#include "../../src/LinkedLists/Cyclic.tpp"