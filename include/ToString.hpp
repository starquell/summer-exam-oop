#pragma once

#include <string>
#include <string_view>
#include <optional>

#include "../src/TypeTraits.hpp"
#include "../src/Utils.hpp"

namespace exam {

    /**
     *  @brief Converts data to human-readable string format
     *  @param delim delimiter for iterable types
     */
    template <typename T>
    auto to_string (const T& data, std::optional<std::string> delim) -> std::string
    {
        if constexpr (std::is_arithmetic_v<T>) {
            return std::to_string(data);
        }
        else if constexpr (detail::is_string<std::remove_reference_t<std::remove_const_t<T>>>) {
            return data;
        }
        else if constexpr (detail::is_container<T>) {
            return utils::join(std::begin(data), std::end(data), delim.value_or(" "));
        }
        else {
            static_assert(detail::always_false<T>, "Not implemented for T");
        }

    }
}