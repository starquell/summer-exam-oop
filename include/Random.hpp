#pragma once

#include "../src/Random.hpp"
#include "../src/TypeTraits.hpp"

#include <stdexcept>

namespace exam {

    /**
     *  @brief Generates random T object
     *  @param size (optional) For container types
     *  @param min Min value of random object
     *  @param max Max value of random object
     */

    template <typename T, typename... Args>
    auto random (Args&&... args) -> T
    {

        if constexpr (std::is_same_v<T, char>) {
            return impl::random_char(std::forward<Args>(args)...);
        }
        else if constexpr (std::is_integral_v<T>) {
            return impl::random_integral<T>(std::forward<Args>(args)...);
        }
        else if constexpr (std::is_floating_point_v<T>) {
            return impl::random_floating<T>(std::forward<Args>(args)...);
        }
        else if constexpr (detail::is_static_container<T>) {
            return impl::random_static_container<T, detail::size_of_static_container<T>>
                    (std::forward<Args>(args)...);
        }
        else if constexpr (detail::is_dynamic_container<T>) {
            return impl::random_dynamic_container<T>(std::forward<Args>(args)...);
        }
        else {
            static_assert(detail::always_false<T>, "Random is not implemented for this type");
        }
    }
}