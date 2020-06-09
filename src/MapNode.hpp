#pragma once

namespace exam::detail {

    template <typename Key, typename Value>
    struct MapNode {
        Key key;
        Value value;
    };

    template <typename Key, typename Value>
    auto operator== (const MapNode<Key, Value>& lhs, const MapNode<Key, Value>& rhs) -> bool
    {
        return lhs.key == rhs.key;
    }

    template <typename Key, typename Value>
    auto operator!= (const MapNode<Key, Value>& lhs, const MapNode<Key, Value>& rhs) -> bool
    {
        return lhs.key != rhs.key;
    }

    template <typename Key, typename Value>
    auto operator< (const MapNode<Key, Value>& lhs, const MapNode<Key, Value>& rhs) -> bool
    {
        return lhs.key < rhs.key;
    }
    template <typename Key, typename Value>
    auto operator> (const MapNode<Key, Value>& lhs, const MapNode<Key, Value>& rhs) -> bool
    {
        return lhs.key > rhs.key;
    }
}

namespace std {

    template <typename Key, typename Value>
    struct hash <exam::detail::MapNode<Key, Value>> {

        auto operator() (const exam::detail::MapNode<Key, Value>& node) const {
            return std::hash<Key>{}(node.key);
        }
    };
}