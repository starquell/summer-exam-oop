#pragma once

#include "ListForwardIterator.hpp"

namespace exam::lists::detail {

    template <typename Node, typename T, typename ListClass>
    class CyclicForwardIterator : public ListForwardIterator<Node, T, ListClass> {
    protected:
        using ListForwardIterator<Node, T, ListClass>::isEnd;
        using ListForwardIterator<Node, T, ListClass>::currentNode;
        using Self = CyclicForwardIterator;

        friend ListClass;

    public:
        using iterator_category = std::forward_iterator_tag;

        CyclicForwardIterator(Node node, bool end = false) :
                ListForwardIterator<Node, T, ListClass>(node, end) {}

        Self& operator++ () {
            if (currentNode->_next) {
                currentNode = currentNode->_next;
            } else {
                isEnd = true;
            }
            return *this;
        }

        using ListForwardIterator<Node, T, ListClass>::operator++;
    };

}