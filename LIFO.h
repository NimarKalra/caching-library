#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


class LIFOPolicy : public EvictionStrategy {
public:
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        // LIFO policy does not require any action when a key is accessed
    }

    int evictKey(list<int>& cacheList) override {
        int keyToEvict = cacheList.back(); // Get the last key in the cache list
        cacheList.pop_back(); // Remove the last key from the cache list
        return keyToEvict;
    }
};