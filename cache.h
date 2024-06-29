#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
#include "strategy.h"
#include "LIFO.h"
#include "FIFO.h"

using namespace std;


enum class EvictionPolicy {
    FIFO,
    LRU,
    LIFO,
};

template<typename Key, typename Value>
class Cache {
public:
    Cache(int capacity, EvictionPolicy policy) : capacity(capacity) {
        switch (policy) {
            case EvictionPolicy::FIFO:
                strategy = make_unique<FIFOPolicy>();
                break;
            case EvictionPolicy::LIFO:
                strategy = make_unique<LIFOPolicy>();
                break;
        }
    }

    void put(const Key &key, const Value &value) {
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

    Value get(const Key &key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            throw invalid_argument("Key does not exist in the cache");
        }

        // Key exists in the cache
        Value value = cacheMap[key].first;
        strategy->keyAccessed(cacheList, cacheMap, key);
        return value;
    
    }

    void printCache() {
        for (auto it = cacheList.begin(); it != cacheList.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

private:
    int capacity;
    unique_ptr<EvictionStrategy> strategy;
    unordered_map<Key, pair<Value, typename list<Key>::iterator>> cacheMap;
    list<Key> cacheList;
};
