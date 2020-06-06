#pragma once

#include <cassert>

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

        class Iterator {
            friend class DoubleLinkedList;
            DLLNode* currentNode;
            bool isEnd = false;

        public:
            explicit Iterator(DLLNode* node, bool end = false) noexcept :
                    currentNode (node) {
                isEnd = !node ? true : end;
            }

            Iterator& operator= (DLLNode* node) {
                assert(node);
                currentNode = node;
                return *this;
            }

            Iterator& operator++ () {
                if (currentNode->_next) {
                    currentNode = currentNode->_next;
                } else {
                    isEnd = true;
                }
                return *this;
            }

            Iterator operator++ (int) {
                Iterator iterator = *this;
                ++*this;
                return iterator;
            }

            Iterator& operator-- () {
                if (isEnd) {
                    isEnd = false;
                } else {
                    if (currentNode->_prev) {
                        currentNode = currentNode->_prev;
                    }
                }
                return *this;
            }

            Iterator operator-- (int) {
                Iterator iterator =*this;
                --*this;
                return iterator;
            }

            bool operator!= (const Iterator& iterator) {
                return (isEnd != iterator.isEnd) && (currentNode != iterator.currentNode);
            }

            bool operator== (const Iterator& iterator) {
                return (isEnd == iterator.isEnd) && (currentNode == iterator.currentNode);
            }

            T& operator* () {
                assert(!isEnd);
                return currentNode->_data;
            }
        };

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