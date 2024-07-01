#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


/**
 * @class LRUPolicy
 * @brief A class that implements the Least Recently Used (LRU) eviction strategy.
 * 
 * The LRUPolicy class is derived from the EvictionStrategy base class and provides
 * methods to handle key accesses and key eviction based on the LRU policy.
 */
class LRUPolicy : public EvictionStrategy {
public:
    /**
     * @brief Updates the cache list and cache map when a key is accessed.
     * 
     * This method is called when a key is accessed in the cache. It updates the cache list
     * and cache map based on the LRU policy. The accessed key is moved to the end of the cache
     * list to indicate that it is the most recently used key.
     * 
     * @param cacheList The cache list containing the keys in the cache.
     * @param cacheMap The cache map containing the key-value pairs and their corresponding iterators in the cache list.
     * @param key The key that was accessed.
     */
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        auto it = cacheMap[key].second;
        cacheList.erase(it);
        cacheList.push_back(key);
        auto newIt = cacheList.end();
        newIt--;
        cacheMap[key].second = newIt;
    }

    /**
     * @brief Evicts the least recently used key from the cache.
     * 
     * This method is called when the cache is full and a new key needs to be inserted.
     * It evicts the least recently used key from the cache based on the LRU policy.
     * The evicted key is removed from the front of the cache list.
     * 
     * @param cacheList The cache list containing the keys in the cache.
     * @return The key that was evicted from the cache.
     */
    int evictKey(list<int>& cacheList) override {
        int keyToEvict = cacheList.front(); // Get the first key in the cache list
        cacheList.pop_front(); // Remove the first key from the cache list
        return keyToEvict;
    }
};