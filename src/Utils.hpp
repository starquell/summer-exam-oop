#pragma once

#include <string>

namespace exam {

    template <typename T>
    auto to_string (const T&, std::optional<std::string> = " ") -> std::string;

    namespace utils {

        template <typename Iter>
        auto join (Iter begin, Iter end, std::string delim = " ") -> std::string {
            std::string result;
            for (; begin != end; ++begin) {

                result += exam::to_string(*begin);

                auto temp = begin;
                if (++temp != end) {
                    result += delim;
                }
            }
            return result;
        }
    }
}