#pragma once

#include "../../src/Trees/BSTBase.hpp"
#include <functional>

namespace exam::tree {

    /**
     *  @brief AVL Tree implementation
     *  T - type of value stored in tree, Compare - comparison function class for elements in tree
     */
    template<typename T,
            typename Compare = std::less<>>
    class AVLTree : public detail::BSTBase<T, Compare, AVLTree<T, Compare>> {
    public:
        /**
         *  @brief Creates tree with no elements
         */
        explicit AVLTree(const Compare &comp = Compare{}) noexcept;

        /**
         *  @brief Constructs tree with elements from range [begin, end)
         */
        template<typename Iter>
        AVLTree(Iter begin, Iter end);

        AVLTree(const AVLTree &other) = default;

        AVLTree(AVLTree &&other) noexcept = default;

        AVLTree &operator=(const AVLTree &other) = default;

        AVLTree &operator=(AVLTree &&other) noexcept = default;

        /**
         *  @brief Constructs tree with elements from list
         */
        AVLTree(std::initializer_list<T> elems);

    private:
        friend class detail::BSTBase<T, Compare, AVLTree<T, Compare>>;

        using NodeAVL = detail::Node<AVLTree<T, Compare>>;

        /**
         *  @brief Inserts element with key _data to tree
         *  @attention Must be used only in insert method in BSTBase
         */
        void insertImpl(const T &key);

        /**
         *  @brief Erases element with key _data from tree
         *  @attention Must be used only in insert method in BSTBase
         */
        void eraseImpl(const T &key);

        using Base = detail::BSTBase<T, Compare, AVLTree<T, Compare>>;

    public:

        ~AVLTree() = default;

    protected:
        using Base::_root;
        using Base::_size;
        using Base::_comp;
    };

    template<typename Iter, typename Compare = std::less<>>
    AVLTree(Iter, Iter) -> AVLTree<typename std::iterator_traits<Iter>::value_type, Compare>;
}

#include "../../src/Trees/AVL/AVLTree.tpp"
#include "../../src/Trees/NodeBase.hpp"