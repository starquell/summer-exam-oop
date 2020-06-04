#pragma once

namespace exam::lists {

    template <typename T>
    typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::begin() {
        return Iterator(_head);
    }

    template <typename T>
    typename DoubleLinkedList<T>::Iterator DoubleLinkedList<T>::end() {
        return Iterator(_tail, true);
    }

    template <typename T>
    DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> elems) {
        for (const auto& elem : elems) {
            insert(elem, end());
        }
    }
    template <typename T>
    template <typename Iter>
    DoubleLinkedList<T>::DoubleLinkedList(Iter _begin, Iter _end) {
        for (; _begin != _end; ++_begin) {
            insert(*_begin, end());
        }
    }
    template <typename T>
    void DoubleLinkedList<T>::insert(const T& data, Iterator iterator) {
        DLLNode* inputNode = new DLLNode(data);
        if (iterator == begin()) {
            if (_head) {
                inputNode->_next = _head;
                _head->_prev = inputNode;
            } else {
                _tail = inputNode;
            }
            _head = inputNode;

        } else if (iterator == end()) {
            DLLNode* curr = _head;
            while (curr->_next) {
                curr = curr->_next;
            }
            curr->_next = inputNode;
            inputNode->_prev = curr;
            _tail = inputNode;
        } else {
            DLLNode* curr = _head;
            while (curr->_data != *iterator && curr->_next) {
                curr = curr->_next;
            }

            inputNode->_next = curr;
            inputNode->_prev = curr->_prev;
            inputNode->_next->_prev = inputNode;
            inputNode->_prev->_next = inputNode;
        }
        _size++;
    }
    template <typename T>
    void DoubleLinkedList<T>::erase(const T& data) {
        DLLNode* curr = _head;
        while (curr) {
            if (curr->_data == data) {
                if (curr->_prev) {
                    curr->_prev->_next = curr->_next;
                } else {
                    _head = _head->_next;
                }
                if (curr->_next) {
                    curr->_next->_prev = curr->_prev;
                } else {
                    _tail = curr->_prev;
                }
                delete curr;
                _size--;
                break;
            }
            curr = curr->_next;
        }
    }

    template <typename T>
    size_t DoubleLinkedList<T>::size() {
        return _size;
    }

    template <typename T>
    DoubleLinkedList<T>::~DoubleLinkedList<T>() {
        DLLNode* curr = _head;
        while (curr) {
            DLLNode* next = curr->_next;
            delete curr;
            curr = next;
        }
        _head = nullptr;
        _tail = nullptr;
    }
}