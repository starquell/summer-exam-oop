#pragma once

#include "SetOperations.hpp"
#include "../include/Set.hpp"


#include <algorithm>

    namespace exam {

        template <typename Key, template<typename...> typename Container>
        Set<Key, Container>::Set(std::initializer_list<value_type> elems)
                : _container(std::move(elems))
        {}

        template <typename Key, template<typename...> typename Container>
        template<typename Iter>
        Set<Key, Container>::Set(Iter begin, Iter end)
                : _container (begin, end)
        {}

        template <typename Key, template<typename...> typename Container>
        inline void Set<Key, Container>::insert(const value_type &value)
        {
            Impl::insert(_container, value);
        }

        template <typename Key, template<typename...> typename Container>
        inline void Set<Key, Container>::insert(iterator, const value_type& value)
        {
            return Impl::insert(_container, value);
        }

        template <typename Key, template<typename...> typename Container>
        inline void Set<Key, Container>::erase(const value_type &value)
        {
            Impl::erase(_container, value);
        }

        template <typename Key, template<typename...> typename Container>
        inline auto Set<Key, Container>::find(const value_type &value) const noexcept -> iterator
        {
            return Impl::find(_container, value);
        }

        template <typename Key, template<typename...> typename Container>
        inline auto Set<Key, Container>::contains(const value_type &value) const noexcept -> bool
        {
            return find(value) != end();
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename...> typename OtherContainer>
        auto Set<Key, Container>::union_with(const Set <Key, OtherContainer> &other) const -> Set <Key, Container>
        {
            Set<Key, Container> result = *this;

            for (const auto& elem : other) {
                result.insert(elem);

            }

            return result;
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename...> typename OtherContainer>
        auto Set<Key, Container>::intersection(const Set <Key, OtherContainer> &other) const -> Set <Key, Container>
        {
            Set<Key, Container> result;

            for (const auto& elem : other) {
                if (contains(elem)) {
                    result.insert(elem);
                }
            }

            return result;
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename...> typename OtherContainer>
        auto Set<Key, Container>::difference(const Set <Key, OtherContainer> &other) const -> Set <Key, Container>
        {
            Set<Key, Container> result;


            for (const auto& elem : *this) {
                if (!other.contains(elem)) {
                    result.insert(elem);
                }
            }

            return result;
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename...> typename OtherContainer>
        auto Set<Key, Container>::symmetric_difference(const Set <Key, OtherContainer> &other) const -> Set <Key, Container>
        {
            Set<Key, Container> result;

            for (const auto& elem : *this) {
                if (!other.contains(elem)) {
                    result.insert(elem);
                }
            }

            for (const auto& elem : other) {
                if (!contains(elem)) {
                    result.insert(elem);
                }
            }

            return result;
        }

        template<typename Key, template<typename...> typename Container>
        inline auto Set<Key, Container>::begin() const noexcept -> iterator
        {
            return _container.begin();
        }

        template<typename Key, template<typename...> typename Container>
        inline auto Set<Key, Container>::end() const noexcept -> iterator
        {
            return _container.end();
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename> typename OtherContainer>
        Set<Key, Container>::Set(const Set <Key, OtherContainer> &other) {
            for (const auto& elem : other) {
                insert(elem);
            }
        }

        template<typename Key, template<typename...> typename Container>
        template<template<typename> typename OtherContainer>
        auto Set<Key, Container>::operator=(const Set <Key, OtherContainer> &other) -> Set<Key, Container>&
        {
            *this = Set<Key, Container>{};
            for (const auto& elem : other) {
                insert(elem);
            }
        }


    }