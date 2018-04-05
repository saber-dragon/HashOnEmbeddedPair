#ifndef PAIR_HASH_HPP
#define PAIR_HASH_HPP

#include <utility>
#include <unordered_map>
#include <hashtable.h>

struct PairHash {
    template<typename T, typename U>
    size_t operator()(const std::pair<T, U> &p) const {
        return PairHash()(p.first) ^ PairHash()(p.second);
    }
    template<typename T>
    size_t operator ()(const T&t) const {
        return std::hash<T>()(t);
    }
};

#endif // PAIR_HASH_HPP