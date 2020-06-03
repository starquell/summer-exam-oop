#pragma once

#include "TypeTraits.hpp"

#include <array>
#include <vector>
#include <random>
#include <string>
#include <type_traits>
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

        template <typename Container, typename T = typename Container::value_type>
        auto random_push_backable (std::size_t size, const T& min, const T& max) -> Container
        {
            Container cont;
            if constexpr (detail::is_reservable<Container>) {
                cont.reserve(size);
            }
            for (auto i = 0; i < size; ++i) {
                cont.push_back(random<T>(min, max));
            }
            return cont;
        }

        template <typename Container, typename T = typename Container::value_type>
        auto random_insertable (std::size_t size, const T& min, const T& max) -> Container
        {
            Container cont;
            for (auto i = 0; i < size; ++i) {
                cont.insert(random<T>(min, max));
            }
            return cont;
        }




    }
}