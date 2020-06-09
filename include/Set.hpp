#pragma once

#include "../src/SetOperations.hpp"

#include <initializer_list>
#include <utility>

namespace exam {

    /**
     *  @brief Wrapper that expands Container operations by set operations
     *  @param Key type of values stored in set
     *  @param impl defines container used as inner implementaion in Set
     *  @param Size (optional) size for static inner containers
     */
    template <typename Key, template<typename...> typename Container>
    class Set {
    public:

        using inner_container = Container<Key>;
        using iterator = typename detail::const_of_default_iterator<Container<Key>>::iterator;
        using value_type = typename inner_container::value_type;

        Set() = default;

        Set (std::initializer_list<value_type> elems);

        template <typename Iter>
        Set (Iter begin, Iter end);

        Set (const Set& other) = default;
        Set (Set&& other) noexcept = default;

        auto operator=(const Set& other) -> Set& = default;
        auto operator=(Set&& other) noexcept -> Set& = default;

        template <template<typename> typename OtherContainer>
        Set (const Set<Key, OtherContainer>& other);

        template <template<typename> typename OtherContainer>
        auto operator=(const Set<Key, OtherContainer>& other) -> Set&;


        /**
         *  @brief Inserts element to set
         *  @param hint for compatibility with std::insert_iterator
         */
        void insert (const value_type& value);

        /**
         *  @brief Inserts element to set
         *  @param hint for compatibility with std::insert_iterator
         */
        void insert (iterator, const value_type& value);

        /**
         *  @brief Erases element from set
         */
        void erase (const value_type& value);

        /**
        *  @return Iterator on value in set, if not found - end()
        */
        auto find (const value_type& value) const noexcept -> iterator;

        /**
         *  @return True if value contained in set
         */
        auto contains (const value_type& value) const noexcept -> bool;

        /**
         *  @return Union of this set and other
         */
        template <template<typename...> typename OtherContainer>
        auto union_with (const Set<Key, OtherContainer>& other) const -> Set<Key, Container>;

        /**
        *  @return Intersection of this set and other
        */
        template <template<typename...> typename OtherContainer>
        auto intersection (const Set<Key, OtherContainer>& other) const -> Set<Key, Container>;

        /**
        *  @return Difference of this set and other
        */
        template <template<typename...> typename OtherContainer>
        auto difference (const Set<Key, OtherContainer>& other) const -> Set<Key, Container>;

        /**
         *  @return Symmetric difference of this set and other
         */
        template <template<typename...> typename OtherContainer>
        auto symmetric_difference (const Set<Key, OtherContainer>& other) const -> Set<Key, Container>;


        auto begin() const noexcept -> iterator;

        auto end() const noexcept -> iterator;

    private:
        using Impl = detail::SetOperations<Container<Key>>;
        Container<Key> _container;
    };


    template <typename KeyLhs, template<typename...> typename ContainerLhs,
              typename KeyRhs, template<typename...> typename ContainerRhs>
    auto operator== (const Set<KeyLhs, ContainerLhs>& lhs, const Set<KeyRhs, ContainerRhs>& rhs) -> bool
    {
        return std::is_permutation(lhs.begin(), lhs.end(), rhs.begin());
    }


    template <typename KeyLhs, template<typename...> typename ContainerLhs,
            typename KeyRhs, template<typename...> typename ContainerRhs>
    auto operator!= (const Set<KeyLhs, ContainerLhs>& lhs, const Set<KeyRhs, ContainerRhs>& rhs) -> bool
    {
        return !(lhs == rhs);
    }
}

#include "../src/Set.tpp"