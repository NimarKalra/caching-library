#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


/**
 * @class LIFOPolicy
 * @brief A class that implements the Last-In-First-Out (LIFO) eviction strategy.
 * 
 * The LIFOPolicy class is derived from the EvictionStrategy base class and provides
 * the implementation for the LIFO eviction strategy. In this strategy, the most recently
 * added key is evicted first when the cache is full.
 */
class LIFOPolicy : public EvictionStrategy {
public:
    /**
     * @brief Handles the access of a key in the cache.
     * 
     * The LIFO policy does not require any action when a key is accessed.
     * 
     * @param cacheList The list representing the cache.
     * @param cacheMap The map representing the cache with key-value pairs and iterators to the cache list.
     * @param key The key that was accessed.
     */
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        // LIFO policy does not require any action when a key is accessed
    }

    /**
     * @brief Evicts a key from the cache using the LIFO policy.
     * 
     * The LIFO policy evicts the most recently added key from the cache.
     * 
     * @param cacheList The list representing the cache.
     * @return The key that is evicted from the cache.
     */
    int evictKey(list<int>& cacheList) override {
        int keyToEvict = cacheList.back(); // Get the last key in the cache list
        cacheList.pop_back(); // Remove the last key from the cache list
        return keyToEvict;
    }
};