#pragma once

#include <type_traits>

namespace exam::detail {

    template <typename InputType, template<typename...> typename Template>
    struct is_template_instantiation_t : std::false_type {};

    template <typename... InputParams, template<typename...> typename Template>
    struct is_template_instantiation_t <Template <InputParams...>, Template> : std::true_type {};

    template <typename InputType, template<typename...> typename Template>
    constexpr inline bool is_template_instantiation = is_template_instantiation_t<InputType, Template>::value;

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

    template<typename T, typename = void>
    inline constexpr bool is_reservable = false;

    template<typename T>
    inline constexpr bool is_reservable<T, std::void_t<
            decltype(std::declval<T>().reverse(std::declval<typename T::size_type>()))
    >> = true;

    template <typename...>
    inline constexpr auto always_false = false;

}

