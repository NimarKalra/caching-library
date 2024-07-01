#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


/**
 * @class FIFOPolicy
 * @brief A class that implements the First-In-First-Out (FIFO) eviction strategy.
 * 
 * The FIFOPolicy class is derived from the EvictionStrategy base class and provides
 * the implementation for the keyAccessed and evictKey methods. The FIFO policy evicts
 * the keys in the same order they were added to the cache.
 */
class FIFOPolicy : public EvictionStrategy {
public:
    /**
     * @brief Performs the necessary actions when a key is accessed.
     * 
     * The FIFO policy does not require any action when a key is accessed.
     * 
     * @param cacheList The list representing the cache.
     * @param cacheMap The map storing the key-value pairs and their corresponding iterators in the cache list.
     * @param key The key that was accessed.
     */
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        // FIFO policy does not require any action when a key is accessed
    }

    /**
     * @brief Evicts a key from the cache using the FIFO policy.
     * 
     * The FIFO policy evicts the first key that was added to the cache.
     * 
     * @param cacheList The list representing the cache.
     * @return The key that was evicted.
     */
    int evictKey(list<int>& cacheList) override {
        int keyToEvict = cacheList.front(); // Get the first key in the cache list
        cacheList.pop_front(); // Remove the first key from the cache list
        return keyToEvict;
    }
};