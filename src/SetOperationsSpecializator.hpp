#pragma once

namespace exam::detail {


    /**
     *  @brief Class for specializing data structure classes methods for Set operations
     */
    template <typename Container>
    struct SetOperations;

    template <typename T>
    struct SetOperations <std::set<T>> {

        using value_type = typename std::set<T>::value_type;

        static auto insert (std::set<T>& container, const value_type& value) -> typename std::set<T>::iterator
        {
            return container.insert(value).first;
        }

        static void erase (std::set<T>& container, const value_type& value)
        {
            container.erase(value);
        }

        static auto contains (const std::set<T>& container, const value_type& value) -> bool
        {
            return container.find(value) != container.end();
        }
    };


}