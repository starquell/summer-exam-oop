#pragma once

#include "../src/Random.hpp"
#include "../src/TypeTraits.hpp"

namespace exam {

    template <typename T, typename... Args>
    auto random (Args&&... args) -> T
    {

        if constexpr (std::is_integral_v<T>) {
            return impl::random_integral(std::forward<Args>(args)...);
        }
        else if constexpr (std::is_floating_point_v<T>) {
            return impl::random_floating(std::forward<Args>(args)...);
        }
        else if constexpr (std::is_same_v<T, char>) {
            return impl::random_char(std::forward<Args>(args)...);
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            return impl::random_string(std::forward<Args>(args)...);
        }
        else if constexpr (detail::has_push_back<T>) {
            return impl::random_push_backable<T>(std::forward<Args>(args)...);
        }
        else if constexpr (detail::has_insert<T>) {
            return impl::random_insertable<T>(std::forward<Args>(args)...);
        }
    }
}