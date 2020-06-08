#pragma once

#include "TypeTraits.hpp"

#include <array>
#include <vector>
#include <random>
#include <string>
#include <limits>
#include <algorithm>
#include <optional>

namespace exam {

    template <typename T, typename... Args>
    auto random (Args&&... args) -> T;

    namespace impl {

        template <typename Integer>
        auto random_integral(Integer min = std::numeric_limits<Integer>::min(),
                             Integer max = std::numeric_limits<Integer>::max()) -> Integer
        {
            static std::mt19937 gen {std::random_device{}()};
            std::uniform_int_distribution<Integer> dist(min, max);
            auto a = dist(gen);
            return a;
        }

        template <typename Floating>
        auto random_floating(Floating min = std::numeric_limits<Floating>::min(),
                             Floating max = std::numeric_limits<Floating>::max()) -> Floating
        {
            static std::mt19937 gen {std::random_device{}()};
            std::uniform_real_distribution<Floating> dist(min, max);
            return dist(gen);
        }

        auto random_char (char min = 32,
                          char max = 126) -> char
        {
            return random_integral<int>(min, max);
        }

        auto random_string (std::size_t size,
                            char min = 32,
                            char max = 126) -> std::string
        {
            std::string str (size, '_');
            std::generate (std::begin(str), std::end(str), [&] { return random_char (min, max); });
            return str;
        }

        template <typename Container, typename... Args>
        auto random_push_backable (std::size_t size, Args&&... range) -> Container
        {
            Container cont;
            if constexpr (detail::is_reservable<Container>) {
                cont.reserve(size);
            }
            for (auto i = 0; i < size; ++i) {
                cont.push_back(random<typename Container::value_type>(std::forward<Args>(range)...));
            }
            return cont;
        }

        template <typename Container, typename... Args>
        auto random_insertable (std::size_t size, Args&&... range) -> Container
        {

            Container cont;
            for (auto i = 0; i < size; ++i) {
                cont.insert(random<typename Container::value_type>(std::forward<Args>(range)...));
            }
            return cont;
        }

        template <typename Container, typename... Args>
        auto random_index_assignable (std::size_t size, Args&&... range) -> Container
        {

            Container cont;
            for (auto i = 0; i < size; ++i) {
                cont[i] = random<typename Container::value_type>(std::forward<Args>(range)...);
            }
            return cont;
        }


        template <typename Container, std::size_t Size, typename... Args>
        auto random_static_container (Args&&... range) -> Container
        {
            if constexpr (detail::has_push_back<Container>) {
                return random_push_backable<Container>(Size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::has_insert<Container>) {
                return random_insertable<Container>(Size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::is_random_index_assignable<Container>) {
                return random_index_assignable<Container>(Size, std::forward<Args>(range)...);
            }
            else {
                static_assert(detail::always_false<Container>, "Random is not implemented for this type");
            }
        }

        template <typename Container, typename... Args>
        auto random_dynamic_container (std::size_t size = 10, Args&&... range) -> Container
        {
            if constexpr (std::is_same_v<Container, std::string>) {
                return random_string(size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::has_push_back<Container>) {
                return random_push_backable<Container>(size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::has_insert<Container>) {
                return random_insertable<Container>(size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::is_random_index_assignable<Container>) {
                return random_index_assignable<Container>(size, std::forward<Args>(range)...);
            }
            else {
                static_assert(detail::always_false<Container>, "Random is not implemented for this type");
            }
        }

    }
}