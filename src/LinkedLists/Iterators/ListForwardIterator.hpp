#pragma once

namespace exam::lists::detail {
    template <typename Node, typename T, typename ListClass>
    class ListForwardIterator {
    protected:
        Node currentNode;
        bool isEnd = false;

        friend ListClass;

        using Self = ListForwardIterator;

    public:

        ListForwardIterator(Node node, bool end = false) noexcept :
        currentNode (node) {
                isEnd = !node ? true : end;
        }

        Self& operator= (Node node) {
            if (!node) {
                isEnd = true;
            }
            currentNode = node;
            return *this;
        }

        virtual Self& operator++ () {
            if (currentNode->_next) {
                currentNode = currentNode->_next;
            } else {
                isEnd = true;
            }
            return *this;
        }

        Self operator++ (int) {
            Self iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!= (const Self& iterator) {
            return (isEnd != iterator.isEnd) && (currentNode != iterator.currentNode);
        }

        bool operator== (const Self& iterator) {
            return (isEnd == iterator.isEnd) && (currentNode == iterator.currentNode);
        }

        T& operator* () {
            assert(currentNode);
            return currentNode->_data;
        }
    };
}

