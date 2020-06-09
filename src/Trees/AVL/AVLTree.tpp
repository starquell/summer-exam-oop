    #pragma once

#include "../NodeBase.hpp"
#include "AVLNodeUtilities.hpp"
#include "DeleteAVLNode.hpp"
#include "InsertAVLNode.hpp"

namespace exam::tree {

    namespace detail {

        template <typename T, typename Compare>
        struct Node<AVLTree<T, Compare>> {
            using NodeAVLT = Node<AVLTree<T, Compare>>;

            T data;
            int height = 1;
            Node<AVLTree<T, Compare>>* left = nullptr;
            Node<AVLTree<T, Compare>>* right = nullptr;
            Node<AVLTree<T, Compare>>* parent = nullptr;
        };
    }

    template <typename T, typename Compare>
    template <typename Iter>
    AVLTree<T, Compare>::AVLTree (Iter begin, Iter end)
    {
        _root = nullptr;
        for (; begin != end; ++begin) {
            this->insert(*begin);
        }
    }

    template <typename T, typename Compare>
    AVLTree<T, Compare>::AVLTree (std::initializer_list<T> elems) {
        for (const auto& elem : elems) {
            this->insert(elem);
        }
    }

    template <typename T, typename Compare>
    void AVLTree<T, Compare>::insertImpl(const T& _data) {
        auto insert = detail::avlutils::InsertAVLNode(_root, _data);
        if (insert.successful()) {
            _size++;
        }
    }

    template <typename T, typename Compare>
    void AVLTree<T, Compare>::eraseImpl(const T& _data) {

        if (_root == nullptr) {
            return;
        }
        detail::Node<AVLTree<T, Compare>>* nodeToDelete = detail::find(_root, _data, _comp);

        if (nodeToDelete == nullptr) {
            return;
        }
        if (nodeToDelete == _root && nodeToDelete->left == nullptr && nodeToDelete->right == nullptr) {
            _root = nullptr;
        } else {
            detail::avlutils::DeleteAVLNode(_root, nodeToDelete->data);
            --_size;
        }
    }

    template <typename T, typename Compare>
    AVLTree<T, Compare>::AVLTree (const Compare& comp) noexcept
            : Base(comp)
    {}
}