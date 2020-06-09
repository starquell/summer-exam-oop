#pragma once

namespace exam {

    template<typename Key, typename Value, template<typename...> typename Container>
    void Map<Key, Value, Container>::insert(const Map<Key, Value, Container>::Node& node) {
        _container.insert(node);
    }

    template<typename Key, typename Value, template<typename...> typename Container>
    void Map<Key, Value, Container>::erase(const key_type& key) {
        _container.erase(Node{key, Value{}});
    }

    template <typename Key, typename Value, template<typename...> typename Container>
    auto Map<Key, Value, Container>::operator[](const key_type &key) const noexcept -> std::optional<value_type>
    {
        auto found = _container.find(Node{key, Value{}});
        return found != _container.end() ? std::optional{(*found).value} : std::nullopt;
    }

    template<typename Key, typename Value, template<typename...> typename Container>
    auto Map<Key, Value, Container>::begin() const noexcept -> iterator
    {
        return _container.begin();
    }

    template <typename Key, typename Value, template<typename...> typename Container>
    auto Map<Key, Value, Container>::end() const noexcept -> iterator
    {
        return _container.end();
    }

    template <typename Key, typename Value, template<typename...> typename Container>
    Map<Key, Value, Container>::Map(std::initializer_list<Node> elems)
            : _container (elems)
    {}

    template <typename Key, typename Value, template<typename...> typename Container>
    template <typename Iter>
    Map<Key, Value, Container>::Map(Iter begin, Iter end)
            : _container (begin, end)
    {}

    template <typename Key, typename Value, template<typename...> typename Container>
    template <template <typename...> typename OtherContainer>
    Map<Key, Value, Container>::Map (const Map<Key, Value, OtherContainer>& other)
            : _container (other.begin(), other.end())
    {}

    template <typename Key, typename Value, template<typename...> typename Container>
    template <template <typename...> typename OtherContainer>
    auto Map<Key, Value, Container>::operator= (const Map<Key, Value, OtherContainer>& other) -> Map<Key, Value, Container>&
    {
        *this = Map<Key, Value, Container>{};
        for (const auto& elem : other) {
            insert(elem);
        }
        return *this;
    }

}