#pragma once

#include "ListForwardIterator.hpp"

namespace exam::lists::detail {

    template <typename Node, typename T, typename ListClass>
    class ListBidirectIterator : public ListForwardIterator<Node, T, ListClass> {
    protected:
        using ListForwardIterator<Node, T, ListClass>::isEnd;
        using ListForwardIterator<Node, T, ListClass>::currentNode;
        using Self = ListBidirectIterator;

        friend ListClass;

    public:
        using iterator_category = std::bidirectional_iterator_tag;

        ListBidirectIterator(Node node, bool end = false) :
                ListForwardIterator<Node, T, ListClass>(node, end) {}

        Self& operator-- () {
            if (isEnd) {
                isEnd = false;
            } else {
                if (currentNode->_prev) {
                    currentNode = currentNode->_prev;
                }
            }
            return *this;
        }

        Self operator-- (int) {
            Self iterator =*this;
            --*this;
            return iterator;
        }
    };

}
