#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include "strategy.h"
#include "LIFO.h"
#include "FIFO.h"
#include "LRU.h"

using namespace std;


enum class EvictionPolicy {
    FIFO,
    LRU,
    LIFO,
    // add custom eviction policy name here and create a new file to define the policy
};

/**
 * @brief Cache class represents a cache with a specified capacity and eviction policy.
 * 
 * The Cache class provides methods to store and retrieve key-value pairs in the cache.
 * When the cache is full, it uses the specified eviction policy to remove a key-value pair
 * in order to make space for a new key-value pair.
 */
class Cache {
public:
    /**
     * @brief Constructs a Cache object with the specified capacity and eviction policy.
     * 
     * @param capacity The maximum number of key-value pairs that the cache can hold.
     * @param policy The eviction policy to be used when the cache is full.
     */
    Cache(int capacity, EvictionPolicy policy) : capacity(capacity) {
        switch (policy) {
            case EvictionPolicy::FIFO:
                strategy = make_unique<FIFOPolicy>();
                break;
            case EvictionPolicy::LIFO:
                strategy = make_unique<LIFOPolicy>();
                break;
            case EvictionPolicy::LRU:
                strategy = make_unique<LRUPolicy>();
                break;
            // add custom eviction policy here
        }
    }

    /**
     * @brief Inserts a key-value pair into the cache.
     * 
     * If the key already exists in the cache, the existing key-value pair is updated with the new value.
     * If the key does not exist in the cache and the cache is full, an existing key-value pair is evicted
     * based on the eviction policy.
     * 
     * @param key The key of the key-value pair.
     * @param value The value of the key-value pair.
     */
    void put(const int &key, const int &value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // Key already exists in the cache
            auto it = cacheMap[key].second;
            cacheList.erase(it);
        } else {
            // Key does not exist in the cache
            if (cacheMap.size() >= capacity) {
                // Cache is full, evict a key
                int keyToEvict = strategy->evictKey(cacheList);
                cacheMap.erase(keyToEvict);
            }
        }

        // Add the key to the cache
        cacheList.push_back(key);
        auto it = cacheList.end();
        it--;
        cacheMap[key] = {value, it};
    }

    /**
     * @brief Retrieves the value associated with the specified key from the cache.
     * 
     * If the key does not exist in the cache, an invalid_argument exception is thrown.
     * If the key exists in the cache, the value is returned and the eviction policy is updated
     * based on the key access.
     * 
     * @param key The key to retrieve the value for.
     * @return The value associated with the key.
     * @throws invalid_argument if the key does not exist in the cache.
     */
    int get(const int &key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            throw invalid_argument("Key does not exist in the cache");
        }

        // Key exists in the cache
        int value = cacheMap[key].first;
        strategy->keyAccessed(cacheList, cacheMap, key);
        return value;
    }
    
    /**
     * @brief Prints the keys in the cache in the order they were accessed.
     */
    void printCache() {
        for (auto it = cacheList.begin(); it != cacheList.end(); it++) {
            int key = *it;
            int value = cacheMap[key].first;
            cout << "Key: " << key << ", Value: " << value << endl;
        }
    }

private:
    int capacity; // The maximum capacity of the cache
    unique_ptr<EvictionStrategy> strategy; // The eviction strategy to be used
    unordered_map<int, pair<int, typename list<int>::iterator>> cacheMap; // Map to store key-value pairs
    list<int> cacheList; // List to maintain the order of key access
};
