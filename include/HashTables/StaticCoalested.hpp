#pragma once

#include <array>
#include <optional>

namespace exam::hashtable {

    /**
     *  @brief Class representing Coalested Hash Table stored on stack
     *
     *  @param Key Type of values stored in table
     *  @param storage Storage type
     *  @param Hash Hash function used for hashing keys
     *  @param Size Size of table for static storage
     */
    template <typename Key,
              std::size_t Size,
              typename Hash = std::hash<Key>>
    class StaticCoalestedHashTable {

        struct Node;

    public:

        class Iterator {
        public:

            using difference_type = std::ptrdiff_t;
            using value_type = const Key&;
            using pointer = const Key*;
            using reference = value_type&;
            using iterator_category = std::forward_iterator_tag;

            explicit Iterator(const std::array<Node, Size>& elem, std::size_t index) noexcept;

            auto operator++ () noexcept -> Iterator&;

            auto operator* () const noexcept -> const Key&;

            auto operator == (const Iterator& other) const noexcept -> bool;
            auto operator != (const Iterator& other) const noexcept -> bool;

        private:
            template <typename _Key,
                      std::size_t _Size,
                      typename _Hash>
            friend class StaticCoalestedHashTable;

            const std::array<Node, Size>& _nodes;
            typename std::array<Node, Size>::const_iterator _curr;
        };

    public:

        using value_type = Key;
        using size_type = std::size_t;
        using iterator = Iterator;
        using const_iterator = Iterator;

        explicit StaticCoalestedHashTable() noexcept = default;

        StaticCoalestedHashTable(std::initializer_list<Key> list) noexcept;

        template<typename Iter>
        StaticCoalestedHashTable (Iter begin, Iter end) noexcept;

        StaticCoalestedHashTable(const StaticCoalestedHashTable& other) = default;
        StaticCoalestedHashTable(StaticCoalestedHashTable&& other) noexcept = default;

        StaticCoalestedHashTable& operator= (const StaticCoalestedHashTable& other) = default;
        StaticCoalestedHashTable& operator= (StaticCoalestedHashTable&& other) noexcept = default;


        auto insert (const value_type & value) noexcept -> Iterator;

        void erase (const value_type& value);

        auto find (const value_type& value) const noexcept -> Iterator;

        auto size() const noexcept -> size_type;

        constexpr static auto max_size() noexcept -> size_type;

        auto begin() const noexcept -> Iterator;

        auto end() const noexcept -> Iterator;

    private:

        auto _hash (const value_type& value);

        struct Node {
            std::optional<Key> value;
            std::optional<typename std::array<Node, Size>::const_iterator> next;

            auto operator== (const Node& other) const noexcept -> bool;
        };

        std::array<Node, Size> _nodes;
        size_type _size{};
        Hash _hashfunc{};
    };




}

#include "../../src/HashTables/StaticCoalested.tpp"