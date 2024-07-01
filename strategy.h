#include <list>
#include <unordered_map>
using namespace std;

/**
 * @brief The EvictionStrategy class is an abstract base class that defines the interface for eviction strategies in a caching library.
 * 
 * This class provides two pure virtual functions that need to be implemented by derived classes:
 * - keyAccessed: This function is called when a key is accessed in the cache. It allows the eviction strategy to update its internal data structures.
 * - evictKey: This function is called when the cache needs to evict a key. It returns the key that should be evicted according to the eviction strategy.
 * 
 * Derived classes should implement these functions based on their specific eviction strategy.
 */
class EvictionStrategy {
public:
    /**
     * @brief Destructor for the EvictionStrategy class.
     */
    virtual ~EvictionStrategy() = default;

    /**
     * @brief This function is called when a key is accessed in the cache.
     * 
     * @param cacheList The list representing the cache.
     * @param cacheMap The map representing the cache, where the key is mapped to a pair of value and iterator in the cacheList.
     * @param key The key that was accessed.
     */
    virtual void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) = 0;

    /**
     * @brief This function is called when the cache needs to evict a key.
     * 
     * @param cacheList The list representing the cache.
     * @return The key that should be evicted according to the eviction strategy.
     */
    virtual int evictKey(list<int>& cacheList) = 0;
};