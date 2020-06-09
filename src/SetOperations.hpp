#pragma once

#include <set>
#include <algorithm>
#include <unordered_set>
#include "TypeTraits.hpp"

#include "../include/Trees/RedBlack.hpp"
#include "../include/Trees/Splay.hpp"
#include "../include/Trees/AVL.hpp"
#include "../include/HashTables/StaticCoalested.hpp"
#include "../include/LinkedLists/DoubleLinked.hpp"
#include "../include/LinkedLists/Cyclic.hpp"
#include "../include/LinkedLists/SinglyLinked.hpp"


namespace exam::detail {


    /**
     *  @brief Class for specializing data structure classes methods for Set operations
     */
    template <typename Container, typename Tag = void>
    struct SetOperations {
        static_assert(always_false<Container>, "Set is not implemented for this type");
    };


    template <typename Container>
    struct SetOperations <Container, std::enable_if_t<
                    detail::is_template_instantiation_of<
                            Container, lists::DoubleLinkedList,
                                       lists::CyclicLinkedList, lists::SinglyLinkedList>>> {

        using value_type = typename Container::value_type;

        static auto insert (Container& container, const value_type& value)
        {
            container.insert(value, std::lower_bound(container.begin(), container.end(), value));
        }

        static void erase (Container& container, const value_type& value)
        {
            container.erase(value);
        }

        static auto find (const Container& container, const value_type& value)
        {
            return std::find(container.begin(), container.end(), value);
        }
    };

    template <typename Container>
    struct SetOperations <Container, std::enable_if_t<
            detail::is_template_instantiation_of<
                    Container, tree::AVLTree,
                               tree::RedBlackTree,
                               tree::SplayTree,
                               std::unordered_set>>> {

        using value_type = typename Container::value_type;

        static void insert (Container& container, const value_type& value)
        {
            container.insert(value);
        }

        static void erase (Container& container, const value_type& value)
        {
            container.erase(value);
        }

        static auto find (const Container& container, const value_type& value)
        {
            return container.find(value);
        }
    };

}