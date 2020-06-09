#pragma once

#include <variant>
#include <set>

#include "Set.hpp"

namespace exam {

    template <typename T, template <typename...> typename... Container>
    class AnySet {

    public:
        using value_type = T;
        using iterator = typename std::set<T>::const_iterator;

        template <template <typename...> typename Container_>
        explicit AnySet(const Set<T, Container_>& set);

        /**
         *  @brief Assigns new set to AnySet
         */
        template <template <typename...> typename Container_>
        void assign (const Set<T, Container_>& set);

        /**
        *  @brief Inserts element to set
        */
        void insert (const value_type& value);

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

        auto union_with (const AnySet& other) const -> AnySet;

        auto intersection (const AnySet& other) const -> AnySet;

        auto difference (const AnySet& other) const -> AnySet;

        auto symmetric_difference (const AnySet& other) const -> AnySet;

        auto begin() const noexcept -> iterator;

        auto end() const noexcept -> iterator;

    private:

        void _enumerate () const;

    private:
        mutable bool _is_valid_iter = true;
        mutable std::set <T> _enumerator;
        std::variant <Set<T, Container>...> _value;
    };
}

#include "../src/AnySet.tpp"