#pragma once

#include <type_traits>
#include <string>
#include <string_view>

#include "../include/HashTables/StaticCoalested.hpp"

namespace exam::detail {

    /////
    /////   Some scary type traits for random and to_string
    /////

    template <typename InputType, template<typename...> typename Template>
    inline constexpr bool is_template_instantiation = false;

    template <typename... InputParams, template<typename...> typename Template>
    inline constexpr bool is_template_instantiation <Template <InputParams...>, Template> = true;

    template <typename T, template<typename...> typename... Templates>
    inline constexpr bool is_template_instantiation_of = (is_template_instantiation <T, Templates> || ...);

    template <typename T>
    inline constexpr bool is_string = std::is_same_v<T, std::string>
                                   || std::is_same_v<T, std::string_view>
                                   || std::is_same_v<T, const char*>;


    template <std::size_t N>
    inline constexpr bool is_string <char[N]> = true;

    template <typename T, typename = void>
    inline constexpr bool has_push_back = false;

    template<typename T>
    inline constexpr auto has_push_back<T, std::void_t<
            decltype(std::declval<T>().push_back(std::declval<typename T::value_type>()))
    >> = true;

    template<typename T, typename = void>
    inline constexpr bool has_insert = false;

    template<typename T>
    inline constexpr auto has_insert<T, std::void_t<
            decltype(std::declval<T>().insert(std::declval<typename T::value_type>()))
    >> = true;


    template <typename T, typename = void>
    inline constexpr bool is_container = std::is_array_v<T>;

    template <typename T>
    inline constexpr bool is_container <T,
            std::void_t<
                std::void_t<typename T::value_type>,
                std::void_t<decltype(std::declval<T>().begin())>,
                std::void_t<decltype(std::declval<T>().end())>>
                            > = true;

    template <typename Container, typename = void>
    inline constexpr bool has_const_iterator = false;

    template <typename Container>
    inline constexpr bool has_const_iterator <Container, std::void_t<typename Container::const_iterator>> = true;

    template <typename Container, typename = void>
    struct const_of_default_iterator {
        using iterator = typename Container::iterator;
    };

    template <typename Container>
    struct const_of_default_iterator <Container, std::enable_if_t<has_const_iterator<Container>>> {
        using iterator = typename Container::const_iterator;
    };

    template <typename T, typename = void>
    inline constexpr bool is_static_container = false;

    template <template <typename, std::size_t> typename T, typename ValueType, std::size_t N>
    inline constexpr bool is_static_container <T<ValueType, N>> = is_container<T<ValueType, N>>;


    template <typename T, std::size_t N>
    inline constexpr bool is_static_container <T[N]> = true;

    template <typename T>
    inline constexpr bool size_of_static_container = false;

    template <template <typename, std::size_t> typename T, typename ValueType, std::size_t N>
    inline constexpr std::size_t size_of_static_container <T<ValueType, N>> = N;

    template <typename T, std::size_t N>
    inline constexpr std::size_t size_of_static_container <T[N]> = N;

    template <typename T>
    inline constexpr bool is_dynamic_container = is_container<T> && !is_static_container<T>;

    template <typename Container, typename = void>
    inline constexpr bool is_random_index_assignable = false;

    template <typename Container>
    inline constexpr bool is_random_index_assignable<Container, std::void_t<
            std::is_same<decltype(std::declval<Container>().operator[](std::declval<typename Container::size_type>())),
                         typename Container::reference>>> = true;


    template<typename T, typename = void>
    inline constexpr bool is_reservable = false;

    template<typename T>
    inline constexpr bool is_reservable<T, std::void_t<
            decltype(std::declval<T>().reserve(std::declval<typename T::size_type>()))
    >> = true;

    template <typename...>
    inline constexpr auto always_false = false;
}

