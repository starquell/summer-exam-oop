#pragma once

#include "../NodeBase.hpp"
#include "AVLNodeUtilities.hpp"

namespace exam::tree::detail::avlutils {

    template <typename T, typename Compare>
    class InsertAVLNode {
    private:
        using AVLNode = Node<AVLTree<T, Compare>>;
        T _data;
        bool inserted = false;

        AVLNode* restoreBalanceForNode(AVLNode* node) {
            node->height = 1 + std::max(height(node->left),
                                   height(node->right));

            int balance = getBalance(node);
            /// Left Left Case
            if (balance > 1 && _data < node->left->data) {
                return avlutils::rightRotate(node);
            }

            /// Right Right Case
            if (balance < -1 && _data > node->right->data) {
                return avlutils::leftRotate(node);
            }

            /// Left Right Case
            if (balance > 1 && _data > node->left->data) {
                node->left = avlutils::leftRotate(node->left);
                return avlutils::rightRotate(node);
            }

            /// Right Left Case
            if (balance < -1 && _data < node->right->data) {
                node->right = avlutils::rightRotate(node->right);
                return avlutils::leftRotate(node);
            }

            return node;
        }

        AVLNode* insertNodeRec (AVLNode* node) {
            if (node == nullptr) {
                inserted = true;
                return new detail::Node<AVLTree<T, Compare>>{_data};
            }

            if (_data < node->data) {
                node->left = insertNodeRec(node->left);
                node->left->parent = node;
            }
            else if (_data > node->data) {
                node->right = insertNodeRec(node->right);
                node->right->parent = node;
            }
            else {
                return node;
            }

            return restoreBalanceForNode(node);
        }

    public:
        InsertAVLNode(AVLNode*& root, const T& data) : _data(data)  {
            root = insertNodeRec(root);
        }

        bool successful() const {
            return inserted;
        }
    };

}