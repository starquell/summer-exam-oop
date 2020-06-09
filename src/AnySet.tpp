#pragma once

namespace exam {

    template<typename T, template <typename...> typename... Containers>
    void AnySet<T, Containers...>::insert(const value_type &value) {
        std::visit([&] (auto& set) {
            set.insert(value);
        }, _value);
        _is_valid_iter = false;
    }

    template<typename T, template <typename...> typename... Containers>
    template<template <typename...> typename Container_>
    void AnySet<T, Containers...>::assign(const Set<T, Container_> & set) {
        _value = set;
        _is_valid_iter = false;
    }

    template<typename T, template <typename...> typename... Containers>
    template<template <typename...> typename Container_>
    AnySet<T, Containers...>::AnySet(const Set<T, Container_>& set)
            : _value (set)
    {
        _enumerate();
    }

    template<typename T, template <typename...> typename... Containers>
    void exam::AnySet<T, Containers...>::erase(const value_type &value) {
        std::visit([&] (auto& set) {
            set.erase(value);
        }, _value);
        _is_valid_iter = false;
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::find(const value_type &value) const noexcept -> exam::AnySet<T, Containers...>::iterator
    {
        if (!_is_valid_iter) {
            _enumerate();
        }
        return _enumerator.find(value);
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::contains(const value_type &value) const noexcept -> bool
    {
        if (!_is_valid_iter) {
            _enumerate();
        }
        return _enumerator.find(value) != _enumerator.end();
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::union_with(const exam::AnySet<T, Containers...> &other) const
    -> exam::AnySet<T, Containers...>
    {
        AnySet result;
        std::visit ([&] (const auto& set) {
            result = set.union_with(other);
        }, _value);

        return result;
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::intersection (const exam::AnySet<T, Containers...> &other) const
    -> exam::AnySet<T, Containers...>
    {
        AnySet result;
        std::visit ([&] (const auto& set) {
            result = set.intersection(other);
        }, _value);

        return result;
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::difference(const exam::AnySet<T, Containers...> &other) const
    -> exam::AnySet<T, Containers...>
    {
        AnySet result;
        std::visit ([&] (const auto& set) {
            result = set.difference(other);
        }, _value);

        return result;
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::symmetric_difference(const exam::AnySet<T, Containers...> &other) const
    -> exam::AnySet<T, Containers...>
    {
        AnySet result;
        std::visit ([&] (const auto& set) {
            result = set.symmetric_difference(other);
        }, _value);

        return result;
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::begin() const noexcept -> exam::AnySet<T, Containers...>::iterator
    {
        if (!_is_valid_iter) {
            _enumerate();
        }
        return _enumerator.begin();
    }

    template<typename T, template <typename...> typename... Containers>
    auto exam::AnySet<T, Containers...>::end() const noexcept -> exam::AnySet<T, Containers...>::iterator
    {
        if (!_is_valid_iter) {
            _enumerate();
        }
        return _enumerator.end();
    }

    template<typename T, template <typename...> typename... Containers>
    void exam::AnySet<T, Containers...>::_enumerate() const {

        if (!_is_valid_iter) {

            std::visit( [&](const auto &set) {
                _enumerator.clear();
                for (const auto& elem : set) {
                    _enumerator.insert(elem);
                }
            }, _value);
        }
    }
}