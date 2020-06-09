#pragma once

#include "Set.hpp"
#include "../src/MapNode.hpp"

#include <optional>

namespace exam {

    /**
     *  @brief Class representing map, adapter on Set class
     */
    template <typename Key,
              typename Value,
              template <typename...> typename Container>
    class Map {

    public:
        using Node = detail::MapNode<Key, Value>;
        using inner_container = Container<Node>;
        using iterator = typename detail::const_of_default_iterator<inner_container>::iterator;
        using key_type = Key;
        using value_type = Value;

        Map() = default;

        Map (std::initializer_list<Node> elems);

        template <typename Iter>
        Map (Iter begin, Iter end);

        Map (const Map& other) = default;
        Map (Map&& other) noexcept = default;

        auto operator=(const Map& other) -> Map& = default;
        auto operator=(Map&& other) noexcept -> Map& = default;

        template <template <typename...> typename OtherContainer>
        Map (const Map<Key, Value, OtherContainer>& other);

        template <template< typename...> typename OtherContainer>
        auto operator=(const Map<Key, Value, OtherContainer>& other) -> Map&;

        /**
         *  @brief Inserts element to set
         */
        void insert (const Node& node);

        /**
         *  @brief Erases element from set
         */
        void erase (const Key& key);

        /**
        *  @return Optional with found value for key, if not found - std::nullopt;
        */
        auto operator[] (const key_type& key) const noexcept -> std::optional<value_type>;

        auto begin() const noexcept -> iterator;

        auto end() const noexcept -> iterator;

    private:
        Set<detail::MapNode<Key, Value>, Container> _container;
    };

    template <typename Key,
              typename Value,
              template<typename...> typename ContainerLhs,
              template<typename...> typename ContainerRhs>
    auto operator== (const Map<Key, Value, ContainerLhs>& lhs, const Map<Key, Value, ContainerRhs>& rhs) -> bool
    {
        return std::is_permutation(lhs.begin(), lhs.end(), rhs.begin());
    }


    template <typename Key,
              typename Value,
            template<typename...> typename ContainerLhs,
            template<typename...> typename ContainerRhs>
    auto operator!= (const Map<Key, Value, ContainerLhs>& lhs, const Map<Key, Value, ContainerRhs>& rhs) -> bool
    {
        return !(lhs == rhs);
    }
}

#include "../src/Map.tpp"