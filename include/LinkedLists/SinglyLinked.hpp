#pragma once

#include "../../src/LinkedLists/Iterators/ListForwardIterator.hpp"

namespace exam::lists {

    template <typename T>
    class SinglyLinkedList {
        struct SLLNode {
            T _data;
            SLLNode* _next = nullptr;

            SLLNode(const T& data) : _data(data) {}
        };

        SLLNode* _head = nullptr;
        SLLNode* _tail = nullptr;
        size_t _size = 0;

    public:
        using iterator = detail::ListForwardIterator<SLLNode*, T, SinglyLinkedList>;

        using value_type = T;

        explicit SinglyLinkedList() = default;

        SinglyLinkedList(std::initializer_list<T> elems);

        template <typename Iter>
        SinglyLinkedList(Iter begin, Iter end);

        SinglyLinkedList(const SinglyLinkedList<T>& other);

        SinglyLinkedList& operator= (const SinglyLinkedList& other);

        iterator begin() const;

        iterator end() const;

        void insert(const T& data, iterator& iterator);
        void insert(const T& data, iterator&& iterator);

        void erase(const T& data);

        [[nodiscard]]
        size_t size() const;

        ~SinglyLinkedList();
    };

}

#include "../../src/LinkedLists/SinglyLinked.tpp"
