#pragma once

namespace exam::tree::detail::avlutils {

    template<typename AVLNode>
    int height(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    template<typename AVLNode>
    int getBalance(AVLNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    template<typename AVLNode>
    AVLNode* rightRotate(AVLNode *nodeToRotate) {
        AVLNode *newRoot = nodeToRotate->left;
        AVLNode *rightOfNewRoot = newRoot->right;

        newRoot->right = nodeToRotate;
        newRoot->parent = nodeToRotate->parent;
        nodeToRotate->left = rightOfNewRoot;
        if (nodeToRotate->left) {
            nodeToRotate->left->parent = nodeToRotate;
        }
        nodeToRotate->parent = newRoot;

        nodeToRotate->height = std::max(height(nodeToRotate->left),
                                   height(nodeToRotate->right)) + 1;

        newRoot->height = std::max(height(newRoot->left),
                              height(newRoot->right)) + 1;

        return newRoot;
    }

    template<typename AVLNode>
    AVLNode* leftRotate(AVLNode *nodeToRotate) {
        AVLNode *newRoot = nodeToRotate->right;
        AVLNode *leftOfNewRoot = newRoot->left;

        newRoot->left = nodeToRotate;
        newRoot->parent = nodeToRotate->parent;
        nodeToRotate->right = leftOfNewRoot;
        if (nodeToRotate->right) {
            nodeToRotate->right->parent = nodeToRotate;
        }
        nodeToRotate->parent = newRoot;

        nodeToRotate->height = std::max(height(nodeToRotate->left), height(nodeToRotate->right)) + 1;
        newRoot->height = std::max(height(newRoot->left), height(newRoot->right)) + 1;

        return newRoot;
    }

}


