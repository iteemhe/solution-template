#ifndef HASHTABLE_H
#define HASHTABLE_H

// Project Identifier: 2C4A3C53CD5AD45A7BEA3AE5356A3B1622C9D04B

// INSTRUCTIONS:
// fill out the methods in the class below.

// You may assume that the key and value types can be copied and have default
// constructors.

// You can also assume that the key type has (==) and (!=) methods.

// You may assume that Hasher is a functor type with a
// size_t operator()(const Key&) overload.

// The key/value types aren't guaranteed to support any other operations.

// Do not add, remove, or change any of the class's member variables.
// The num_deleted counter is *optional*. You might find it helpful, but it
// is not required to pass the lab assignment.

// Do not change the Bucket type.

// SUBMISSION INSTRUCTIONS:
// Submit this file, by itself, in a .tar.gz.
// Other files will be ignored.

#include <cassert> // useful for debugging!
#include <cmath>
#include <cstdint>
#include <functional> // where std::hash lives
#include <iostream>
#include <vector>

// A bucket's status tells you whether it's empty, occupied,
// or contains a deleted element.
enum class Status : uint8_t { Empty, Occupied, Deleted };

template <typename K, typename V, typename Hasher = std::hash<K>>
class HashTable {
    // used by the autograder; do not change/remove.
    friend class Verifier;
    using ull = uint64_t;
    constexpr static Hasher hasher = Hasher();

public:
    int collisions = 0;

    // A bucket has a status, a key, and a value.
    struct Bucket {
        // Do not modify Bucket.
        Status status = Status::Empty;
        K key;
        V val;
    };

    HashTable() {
        buckets.resize(17);
    }

    [[nodiscard]] size_t size() const {
        return num_elements;
    }

    // returns a reference to the value in the bucket with the key, if it
    // already exists. Otherwise, insert it with a default value, and return
    // a reference to the resulting bucket.
    V &operator[](const K &key) {
        auto &&hash_val = hasher(key);
        auto &&idx = hash_val % buckets.size();
        auto old_idx = idx;
        while (buckets[idx].status == Status::Occupied) {
            if (buckets[idx].key == key) return buckets[idx].val;
            if (++idx == buckets.size()) idx -= buckets.size();
            ++collisions;
        }
        auto pos = idx;
        while (buckets[idx].status != Status::Empty) {
            if (buckets[idx].status == Status::Occupied && buckets[idx].key == key)
                return buckets[idx].val;
            if (++idx == buckets.size()) idx -= buckets.size();
            // ++collisions;
            if (idx == old_idx) break;
        }
        buckets[pos] = {Status::Occupied, key, V{}};
        if (static_cast<double>(++num_elements) / static_cast<double>(buckets.size()) >= 0.5) {
            rehash_and_grow();
            return this->operator[](key);
        }
        return buckets[pos].val;
    }

    // insert returns whether inserted successfully
    // (if the key already exists in the table, do nothing and return false).
    bool insert(const K &key, const V &val) {
        auto &&hash_val = hasher(key);
        auto &&idx = hash_val % buckets.size();
        auto old_idx = idx;
        while (buckets[idx].status == Status::Occupied) {
            if (buckets[idx].key == key) return false;
            if (++idx == buckets.size()) idx -= buckets.size();
            ++collisions;
        }
        auto pos = idx;
        while (buckets[idx].status != Status::Empty) {
            if (buckets[idx].status == Status::Occupied && buckets[idx].key == key) return false;
            if (++idx == buckets.size()) idx -= buckets.size();
            // ++collisions;
            if (idx == old_idx) break;
        }
        buckets[pos] = {Status::Occupied, key, val};
        if (static_cast<double>(++num_elements) / static_cast<double>(buckets.size()) >= 0.5)
            rehash_and_grow();
        return true;
    }
    // erase returns the number of items remove (0 or 1)
    size_t erase(const K &key) {
        auto &&hash_val = hasher(key);
        auto &&idx = hash_val % buckets.size();
        auto old_idx = idx;
        while (buckets[idx].status != Status::Empty) {
            if (buckets[idx].status == Status::Occupied && buckets[idx].key == key) {
                buckets[idx].status = Status::Deleted;
                --num_elements;
                return 1;
            }
            if (++idx == buckets.size()) idx -= buckets.size();
            ++collisions;
            if (idx == old_idx) break;
        }
        return 0;
    }

private:
    size_t num_elements = 0;
    std::vector<Bucket> buckets;

    auto is_prime(size_t n) -> bool {
        auto sqrtn = static_cast<size_t>(std::ceil(std::sqrt(n)));
        for (size_t i{2}; i < sqrtn; ++i)
            if (n % i == 0) return false;
        return true;
    }

    void rehash_and_grow() {
        size_t next_prime = buckets.size() * 2;
        while (!is_prime(next_prime)) ++next_prime;
        std::vector<Bucket> temp(next_prime);

        //        std::cout << next_prime << '\n';

        for (auto &&b : buckets) {
            if (b.status == Status::Occupied) {
                auto &&hash_val = hasher(b.key);
                auto &&idx = hash_val % temp.size();
                while (temp[idx].status == Status::Occupied)
                    if (++idx == temp.size()) idx -= temp.size();
                temp[idx] = {Status::Occupied, std::move(b.key), std::move(b.val)};
            }
        }
        std::swap(temp, buckets);
    }
};

#endif // HASHTABLE_H
