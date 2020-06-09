#pragma once

namespace exam::lists {

    template <typename T>
    typename CyclicLinkedList<T>::iterator CyclicLinkedList<T>::begin() {
        return iterator(_head);
    }

    template <typename T>
    typename CyclicLinkedList<T>::iterator CyclicLinkedList<T>::end() {
        return iterator(_tail, true);
    }

    template <typename T>
    CyclicLinkedList<T>::CyclicLinkedList(std::initializer_list<T> elems) {
        for (const auto& elem : elems) {
            insert(elem, end());
        }
    }

    template <typename T>
    template <typename Iter>
    CyclicLinkedList<T>::CyclicLinkedList(Iter _begin, Iter _end) {
        for (; _begin != _end; ++_begin) {
            insert(*_begin, end());
        }
    }

    template <typename T>
    CyclicLinkedList<T>::CyclicLinkedList(const CyclicLinkedList<T>& other) {
        auto curr = other._head;
        do {
            insert(curr->_data, end());
            curr = curr->_next;
        } while (curr != other._head);
    }

    template<typename T>
    CyclicLinkedList<T>&
    CyclicLinkedList<T>::operator= (const CyclicLinkedList& other) {
        if (&other == this) {
            return *this;
        }

        _head = nullptr;
        _tail = nullptr;
        auto curr = other._head;
        do {
            insert(curr->_data, end());
            curr = curr->_next;
        } while (curr != other._head);
        _size = other._size;

        return *this;
    }

    template <typename T>
    void CyclicLinkedList<T>::insert(const T& data, iterator& iterator) {
        if (!_head) {
            _head = new SLLNode(data);
            _head->_next = _head;
            _tail = _head;
            iterator.currentNode = _tail;
        } else if (iterator == end()){
            auto inputNode = new SLLNode(data);
            auto iterNode = iterator.currentNode;
            iterNode->_next = inputNode;
            inputNode->_next = _head;
            _tail = inputNode;
            iterator.currentNode = _tail;
        } else {
            auto iterNode = iterator.currentNode;
            SLLNode* inputNode = new SLLNode(iterNode->_data);
            iterNode->_data = data;
            inputNode->_next = iterNode->_next;
            iterNode->_next = inputNode;
            iterator.currentNode = inputNode;
        }
        _size++;
    }

    template <typename T>
    void CyclicLinkedList<T>::insert(const T& data, iterator&& iterator) {
        auto iterRef = iterator;
        insert(data, iterRef);
    }

    template <typename T>
    void CyclicLinkedList<T>::erase(const T& data) {
        SLLNode* curr = _tail;
        do {
            if (curr->_next->_data == data) {
                auto toDelete = curr->_next;
                if (toDelete == _head) {
                    if (toDelete == _tail) {
                        _head = _tail = nullptr;
                    } else {
                        _head = toDelete->_next;
                    }
                } else if (toDelete == _tail) {
                    _tail = curr;
                }
                curr->_next = toDelete->_next;
                delete toDelete;
                _size--;
                break;
            }
            curr = curr->_next;
        } while (curr != _tail);
    }

    template <typename T>
    size_t CyclicLinkedList<T>::size() const {
        return _size;
    }

    template <typename T>
    CyclicLinkedList<T>::~CyclicLinkedList<T>() {
        SLLNode* curr = _head;
        SLLNode* next = _head->_next;

        if (next) {
            curr->_next = nullptr;
        }
        curr = next;

        while (curr) {
            next = curr->_next;
            delete curr;
            curr = next;
        }
    }
}