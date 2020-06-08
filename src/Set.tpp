    #pragma once

    #include "../include/Set.hpp"
    #include "SetOperationsSpecializator.hpp"

    #include <algorithm>

    namespace exam {

        template<typename Container>
        Set<Container>::Set(std::initializer_list<value_type> elems)
                : _container(std::move(elems))
        {}

        template<typename Container>
        template<typename Iter>
        Set<Container>::Set(Iter begin, Iter end)
                : _container (begin, end)
        {}

        template<typename Container>
        inline auto Set<Container>::insert(const value_type &value) -> iterator
        {
            return Impl::insert(_container, value);
        }

        template<typename Container>
        inline auto Set<Container>::insert(iterator, const value_type &value) -> iterator
        {
            return Impl::insert(_container, value);
        }


        template<typename Container>
        inline void Set<Container>::erase(const value_type &value)
        {
            Impl::erase(_container, value);
        }

        template<typename Container>
        inline auto Set<Container>::contains(const value_type &value) const noexcept -> bool
        {
            return Impl::contains(_container, value);
        }

        template<typename Container>
        template<typename OtherContainer>
        auto Set<Container>::union_with(const Set <OtherContainer> &other) const -> Set <Container>
        {
            Set<Container> result = *this;

            std::copy(other.begin(), other.end(), std::inserter(result, result.end()));

            return result;
        }

        template<typename Container>
        template<typename OtherContainer>
        auto Set<Container>::intersection(const Set <OtherContainer> &other) const -> Set <Container>
        {
            Set<Container> result;

            std::copy_if(other.begin(), other.end(),
                        std::inserter(result, result.end()),
                        [this] (const auto& elem) {
                return contains(elem);
            });

            return result;
        }

        template<typename Container>
        template<typename OtherContainer>
        auto Set<Container>::difference(const Set <OtherContainer> &other) const -> Set <Container>
        {
            Set<Container> result;

            std::copy_if(begin(), end(), std::inserter(result, result.end()),
                    [other] (const auto& elem) {
                return !other.contains(elem);
            });

            return result;
        }

        template<typename Container>
        template<typename OtherContainer>
        auto Set<Container>::symmetric_difference(const Set <OtherContainer> &other) const -> Set <Container>
        {
            Set<Container> result;

            std::copy_if(begin(), end(), std::inserter(result, result.end()),
                         [&other] (const auto& elem) {
                             return !other.contains(elem);
            });

            std::copy_if(other.begin(), other.end(), std::inserter(result, result.end()),
                         [this] (const auto& elem) {
                             return !contains(elem);
            });

            return result;
        }

        template<typename Container>
        inline auto Set<Container>::begin() const noexcept -> iterator
        {
            return _container.begin();
        }

        template<typename Container>
        inline auto Set<Container>::end() const noexcept -> iterator
        {
            return _container.end();
        }
    }