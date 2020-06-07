#pragma once

#include "../src/SetOperationsSpecializator.hpp"

#include <initializer_list>
#include <utility>

namespace exam {

    /**
     *  @brief Wrapper that expandes Container operations by set operations
     */

    template <typename Container>
    class Set {

    public:
        using iterator = typename Container::iterator;
        using const_iterator = iterator;
        using value_type = typename Container::value_type;

        Set() = default;

        Set (std::initializer_list<value_type> elems);

        template <typename Iter>
        Set (Iter begin, Iter end);

        Set (const Set& other) = default;
        Set (Set&& other) noexcept = default;

        Set& operator=(const Set& other) = default;
        Set& operator=(Set&& other) noexcept = default;

        template <typename OtherContainer>
        Set (const Set<OtherContainer>& other);

        template <typename OtherContainer>
        Set (Set<OtherContainer>&& other) noexcept;

        template <typename OtherContainer>
        Set& operator=(const Set<OtherContainer>& other);

        template <typename OtherContainer>
        Set& operator=(Set<OtherContainer>&& other) noexcept;

        /**
         *  @brief Inserts element to set
         *  @param hint for compatibility with std::insert_iterator
         */
        auto insert (const value_type& value) -> iterator;

        /**
         *  @brief Inserts element to set
         *  @param hint for compatibility with std::insert_iterator
         */
        auto insert (iterator, const value_type& value) -> iterator;

        /**
         *  @brief Erases element from set
         */
        void erase (const value_type& value);

        /**
         *  @return True if value contained in set
         */
        auto contains (const value_type& value) const noexcept -> bool;

        /**
         *  @return Union of this set and other
         */
        template <typename OtherContainer>
        auto union_with (const Set<OtherContainer>& other) const -> Set<Container>;

        /**
        *  @return Intersection of this set and other
        */
        template <typename OtherContainer>
        auto intersection (const Set<OtherContainer>& other) const -> Set<Container>;

        /**
        *  @return Difference of this set and other
        */
        template <typename OtherContainer>
        auto difference (const Set<OtherContainer>& other) const -> Set<Container>;

        /**
         *  @return Symmetric difference of this set and other
         */
        template <typename OtherContainer>
        auto symmetric_difference (const Set<OtherContainer>& other) const -> Set<Container>;


        auto begin() const noexcept -> iterator;

        auto end() const noexcept -> iterator;

    private:
        using Impl = detail::SetOperations<Container>;
        Container _container;
    };


    template <typename ContainerLhs, typename ContainerRhs>
    auto operator== (const Set<ContainerLhs>& lhs, const Set<ContainerRhs>& rhs) -> bool
    {
        return std::all_of(lhs.begin(), lhs.end(),
                           [&rhs] (const auto& elem) {return rhs.contains(elem);})
                           &&
              std::all_of(rhs.begin(), rhs.end(),
                           [&lhs] (const auto& elem) {return lhs.contains(elem);});
    }

    template <typename ContainerLhs, typename ContainerRhs>
    auto operator!= (const Set<ContainerLhs>& lhs, const Set<ContainerRhs>& rhs) -> bool
    {
        return !(lhs == rhs);
    }


}

#include "../src/Set.tpp"