#pragma once

#include <type_traits>

namespace exam::detail {


    template <typename InputType, template<typename...> typename Template>
    inline constexpr bool is_template_instantiation = false;

    template <typename... InputParams, template<typename...> typename Template>
    inline constexpr bool is_template_instantiation <Template <InputParams...>, Template> = true;

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
    inline constexpr bool is_container = false;

    template <typename T>
    inline constexpr bool is_container <T, std::void_t<
                std::void_t<typename T::value_type>,
                std::void_t<decltype(std::declval<T>().begin())>,
                std::void_t<decltype(std::declval<T>().end())>>> = true;


    template<typename T, typename = void>
    inline constexpr bool is_reservable = false;

    template<typename T>
    inline constexpr bool is_reservable<T, std::void_t<
            decltype(std::declval<T>().reverse(std::declval<typename T::size_type>()))
    >> = true;

    template <typename...>
    inline constexpr auto always_false = false;

}

