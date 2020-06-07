#pragma once

#include "cassert"
#include "../../src/LinkedLists/Iterators/ListBidirectIterator.hpp"

namespace exam::lists {

    template <typename T>
    class DoubleLinkedList {
        struct DLLNode {
            T _data;
            DLLNode* _next = nullptr;
            DLLNode* _prev = nullptr;

            DLLNode(const T& data) : _data(data) {}
        };

        DLLNode* _head = nullptr;
        DLLNode* _tail = nullptr;
        size_t _size = 0;

    public:
        using Iterator = detail::ListBidirectIterator<DLLNode*, T, DoubleLinkedList>;

        using value_type = T;

        explicit DoubleLinkedList() = default;

        DoubleLinkedList(std::initializer_list<T> elems);

        template <typename Iter>
        DoubleLinkedList(Iter begin, Iter end);

        DoubleLinkedList(const DoubleLinkedList<T>& other);

        DoubleLinkedList& operator= (const DoubleLinkedList& other);

        Iterator begin();

        Iterator end();

        void insert(const T& data, Iterator iterator);

        void erase(const T& data);

        [[nodiscard]]
        size_t size() const;

        ~DoubleLinkedList();
    };

}

#include "../../src/LinkedLists/DoubleLinked.tpp"