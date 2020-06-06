#pragma once

#include "TypeTraits.hpp"

#include <array>
#include <vector>
#include <random>
#include <string>
#include <limits>
#include <algorithm>

namespace exam {

    template <typename T, typename... Args>
    auto random (Args&&... args) -> T;

    namespace impl {

        template <typename Integer>
        auto random_integral(Integer min = std::numeric_limits<Integer>::min(),
                             Integer max = std::numeric_limits<Integer>::max()) -> Integer
        {
            static std::mt19937 gen {std::random_device{}()};
            static std::uniform_int_distribution<Integer> dist(min, max);
            return dist(gen);
        }

        template <typename Floating>
        auto random_floating(Floating min = std::numeric_limits<Floating>::min(),
                             Floating max = std::numeric_limits<Floating>::max()) -> Floating
        {
            static std::mt19937 gen {std::random_device{}()};
            static std::uniform_real_distribution<Floating> dist(min, max);
            return dist(gen);
        }

        auto random_char (char min = std::numeric_limits<char>::min(),
                          char max = std::numeric_limits<char>::max()) -> char
        {
            return static_cast<char>(random_integral<int>(min, max));
        }

        auto random_string (std::size_t size,
                            char min = std::numeric_limits<char>::min(),
                            char max = std::numeric_limits<char>::max()) -> std::string
        {
            std::string str (size, '_');
            std::generate (std::begin(str), std::end(str), [&] { return random_char (min, max); });
            return str;
        }

        template <typename Container, typename... Args>
        auto random_push_backable (std::size_t size, Args&&... range) -> Container
        {
            static_assert((std::is_same_v<typename Container::value_type, Args> && ...));

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
            static_assert((std::is_same_v<typename Container::value_type, Args> && ...));

            Container cont;
            for (auto i = 0; i < size; ++i) {
                cont.insert(random<typename Container::value_type>(std::forward<Args>(range)...));
            }
            return cont;
        }

        template <typename Container, typename... Args>
        auto random_container (std::size_t size, Args&&... range) -> Container
        {
            static_assert((std::is_same_v<typename Container::value_type, Args> && ...));

            if constexpr (std::is_same_v<Container, std::string>) {
                return random_string(size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::has_push_back<Container>) {
                return random_push_backable<Container>(size, std::forward<Args>(range)...);
            }
            else if constexpr (detail::has_insert<Container>) {
                return random_insertable<Container>(size, std::forward<Args>(range)...);
            }
            else {
                static_assert(detail::always_false<Container>);
            }
        }








    }
}