#pragma once

#include "../../include/HashTables/StaticCoalested.hpp"

namespace exam::hashtable {

    template <typename Key,
             std::size_t Size,
              typename Hash>
    StaticCoalestedHashTable<Key, Size, Hash>::StaticCoalestedHashTable(std::initializer_list<Key> list)
    {

        for (const auto& elem : list) {
            insert(elem);
        }
    }

    template <typename Key,
             std::size_t Size,
             typename Hash>
    template<typename Iter>
    StaticCoalestedHashTable<Key, Size, Hash>::StaticCoalestedHashTable(Iter begin, Iter end)
    {
        for (; begin != end; ++begin) {
            insert(*begin);
        }
    }

    template <typename Key,
              std::size_t Size,
              typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::insert(const Key &value) -> StaticCoalestedHashTable::Iterator
    {
        auto pos = _hashfunc(value) % Size;
        bool inserted = false;

        if (_nodes[pos].value) {

            while (_nodes[pos].value) {
                if (*_nodes[pos].value == value) {
                    return Iterator {_nodes,  pos};
                }
                if (_nodes[pos].next) {
                    pos = *_nodes[pos].next;
                }
                else {
                    break;
                }
            }

            for (auto i = pos - 1; i >= 0; --i) {
                if (!_nodes[i].value) {
                    _nodes[pos].next = i;
                    _nodes[i].value = value;
                    pos = i;
                    inserted = true;
                    break;
                }
            }
        }
        else {
            _nodes[pos].value = value;
            inserted = true;
        }
        ++_size;
        return inserted ? Iterator{_nodes, pos}
                        : Iterator {_nodes, _nodes.size()};
    }

    template <typename Key,
             std::size_t Size,
             typename Hash>
    void StaticCoalestedHashTable<Key, Size, Hash>::erase(const Key &value) {

        auto pos = _hashfunc(value) % Size;
        auto prev = pos;

        while (_nodes[pos].value && *_nodes[pos].value != value) {
            if (_nodes[pos].next) {
                prev = pos;
                pos = *_nodes[pos].next;
            }

            else {
                return;
            }
        }
        if (!_nodes[pos].value) {
            return;
        }
        _nodes[pos].value = std::nullopt;
        if (prev != pos) {
            _nodes[prev].next = _nodes[pos].next;
        }
        _nodes[pos].next = std::nullopt;
        --_size;
    }

    template <typename Key,
              std::size_t Size,
              typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::find(const Key &value) -> StaticCoalestedHashTable::Iterator
    {
        const auto pos = _hashfunc(value) % Size;

        while (_nodes[pos].value && *_nodes[pos].value != value) {
            if (_nodes[pos].next) {
                pos = *_nodes[pos].next;
            }
            else {
                return Iterator {_nodes.cend()};
            }
        }
        return Iterator{_nodes.cbegin() + pos};
    }

    template <typename Key,
              std::size_t Size,
              typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::
            insert_hint(const Key &value, StaticCoalestedHashTable::Iterator last_in_chain) -> StaticCoalestedHashTable::Iterator

    {
        const auto pos = last_in_chain._elem - _nodes.begin();

        bool inserted = false;

        for (auto i = pos - 1; i >= 0; --i) {
            if (!_nodes[i].value) {
                *_nodes[pos].next = i;
                *_nodes[i].value = value;
                pos = i;
                inserted = true;
                break;
            }
        }

        return inserted ? Iterator {_nodes.cbegin() + pos}
                        : Iterator {_nodes.cend()};
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::size() const noexcept -> StaticCoalestedHashTable::size_type
    {
        return _size;
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::begin() const noexcept -> StaticCoalestedHashTable::Iterator
    {
        return Iterator{_nodes, 0};
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::end() const noexcept -> StaticCoalestedHashTable::Iterator
    {
        return Iterator {_nodes, _nodes.size()};
    }

    template<typename Key, std::size_t Size, typename Hash>
    StaticCoalestedHashTable<Key, Size, Hash>::Iterator::Iterator(const std::array<
            StaticCoalestedHashTable<Key, Size, Hash>::Node, Size>& nodes, std::size_t index)
            : _nodes (nodes),
              _curr (nodes.cbegin() + index)
    {
        while (!_curr->value && _curr != _nodes.cend()) {
            ++_curr;
        }
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::Iterator::operator++() -> StaticCoalestedHashTable::Iterator&
    {
        do {
            ++_curr;
        }
        while (!_curr->value && _curr != _nodes.end());
        return *this;
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::Iterator::operator*() -> const Key &
    {
        return *_curr->value;
    }

    template<typename Key, std::size_t Size, typename Hash>
    auto StaticCoalestedHashTable<Key, Size, Hash>::Iterator::
            operator!= (const StaticCoalestedHashTable<Key, Size, Hash>::Iterator& other) -> bool
    {
        return _curr != other._curr;
    }
}