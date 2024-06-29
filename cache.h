#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;

class EvictionStrategy {
public:
    virtual ~EvictionStrategy() = default;
    virtual void keyAccessed(list<int>& cacheList, unordered_map<int, list<int>::iterator>& cacheMap, int key) = 0;
    virtual int evictKey(list<int>& cacheList) = 0;
};

class FIFOPolicy : public EvictionStrategy {
    // FIFO eviction logic
};

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
            case EvictionPolicy::LRU:
                strategy = make_unique<LRUPolicy>();
                break;
            case EvictionPolicy::LIFO:
                strategy = make_unique<LIFOPolicy>();
                break;
        }
    }

    void put(const Key &key, const Value &value) {
    }

    Value get(const Key &key) {
    }

    void printCache() {
    }

private:
    int capacity;
    unique_ptr<EvictionStrategy> strategy;
    unordered_map<Key, pair<Value, typename list<Key>::iterator>> cacheMap;
    list<Key> cacheList;
};
