#pragma once

namespace exam::lists {

    template <typename T>
    typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::begin() {
        return iterator(_head);
    }

    template <typename T>
    typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::end() {
        return iterator(_tail, true);
    }

    template <typename T>
    SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> elems) {
        for (const auto& elem : elems) {
            insert(elem, end());
        }
    }

    template <typename T>
    template <typename Iter>
    SinglyLinkedList<T>::SinglyLinkedList(Iter _begin, Iter _end) {
        for (; _begin != _end; ++_begin) {
            insert(*_begin, end());
        }
    }

    template <typename T>
    SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& other) {
        auto curr = other._head;
        while (curr) {
            insert(curr->_data, end());
            curr = curr->_next;
        }
    }

    template<typename T>
    SinglyLinkedList<T>&
    SinglyLinkedList<T>::operator= (const SinglyLinkedList& other) {
        if (&other == this) {
            return *this;
        }

        _head = nullptr;
        _tail = nullptr;
        auto curr = other._head;
        while (curr) {
            insert(curr->_data, end());
            curr = curr->_next;
        }
        _size = other._size;

        return *this;
    }

    template <typename T>
    void SinglyLinkedList<T>::insert(const T& data, iterator& iterator) {
        if (!_head) {
            _head = new SLLNode(data);
            _tail = _head;
            iterator.currentNode = _tail;
        } else if (iterator == end()){
            auto inputNode = new SLLNode(data);
            auto iterNode = iterator.currentNode;
            iterNode->_next = inputNode;
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
    void SinglyLinkedList<T>::insert(const T& data, iterator&& iterator) {
        auto iterRef = iterator;
        insert(data, iterRef);
    }

    template <typename T>
    void SinglyLinkedList<T>::erase(const T& data) {
        SLLNode* curr = _head;
        if (curr->_data == data) {
            if (curr == _tail) {
                _head = _tail = nullptr;
            } else {
                _head = _head->_next;
            }
            delete curr;
            _size--;
            return;
        }
        while (curr->_next) {
            if (curr->_next->_data == data) {
                auto toDelete = curr->_next;
                if (toDelete == _tail) {
                    _tail = curr;
                }
                curr->_next = toDelete->_next;
                delete toDelete;
                _size--;
                break;
            }
            curr = curr->_next;
        }
    }

    template <typename T>
    size_t SinglyLinkedList<T>::size() const {
        return _size;
    }

    template <typename T>
    SinglyLinkedList<T>::~SinglyLinkedList<T>() {
        SLLNode* curr = _head;
        while (curr) {
            SLLNode* next = curr->_next;
            delete curr;
            curr = next;
        }
    }
}