#pragma once

#include "../NodeBase.hpp"
#include "AVLNodeUtilities.hpp"

namespace exam::tree::detail::avlutils {

    template <typename T, typename Compare>
    class DeleteAVLNode {
    private:
        using AVLNode = Node<AVLTree<T, Compare>>;

        AVLNode* restoreBalanceForNode(AVLNode* node) {
            int balance = getBalance(node);

            if (balance > 1 && getBalance(node->left) >= 0) {
                return detail::avlutils::rightRotate(node);
            }

            if (balance > 1 && getBalance(node->left) < 0) {
                node->left = detail::avlutils::leftRotate(node->left);
                return detail::avlutils::rightRotate(node);
            }

            if (balance < -1 && getBalance(node->right) <= 0) {
                return detail::avlutils::leftRotate(node);
            }

            if (balance < -1 && getBalance(node->right) > 0) {
                node->right = detail::avlutils::rightRotate(node->right);
                return detail::avlutils::leftRotate(node);
            }

            return node;
        }

        AVLNode* deleteNode(AVLNode* node, const T& _data) {
            if (_data < node->data) {
                node->left = deleteNodeRec(node->left, _data);
                if (node->left) {
                    node->left->parent = node;
                }
            }
            else if (_data > node->data) {
                node->right = deleteNodeRec(node->right, _data);
                if (node->right) {
                    node->right->parent = node;
                }
            } else {
                if (node->left == nullptr || node->right == nullptr) {
                    AVLNode* child = node->left ? node->left : node->right;
                    if (child == nullptr) {
                        child = node;
                        node = nullptr;
                    } else {
                        AVLNode* parent = node->parent;
                        *node = *child;
                        node->parent = parent;
                    }
                    delete child;
                } else {
                    AVLNode* min = detail::min(node->right);
                    node->data = min->data;
                    node->right = deleteNodeRec(node->right, min->data);
                    if (node->right) {
                        node->right->parent = node;
                    }
                }
            }
            return node;
        }

        AVLNode* deleteNodeRec (AVLNode* node, const T& _data) {
            if (node == nullptr) {
                return node;
            }

            node = deleteNode(node, _data);

            if (node == nullptr) {
                return node;
            }

            node->height = 1 + std::max(height(node->left), height(node->right));
            return restoreBalanceForNode(node);

        }

    public:
        DeleteAVLNode(AVLNode*& root, const T& _data)   {
            root = deleteNodeRec(root, _data);
        }
    };

}
