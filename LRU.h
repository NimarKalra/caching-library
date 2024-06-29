#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


class LRUPolicy : public EvictionStrategy {
public:
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        auto it = cacheMap[key].second;
        cacheList.erase(it);
        cacheList.push_back(key);
        auto newIt = cacheList.end();
        newIt--;
        cacheMap[key].second = newIt;
    }

    int evictKey(list<int>& cacheList) override {
        int keyToEvict = cacheList.front(); // Get the first key in the cache list
        cacheList.pop_front(); // Remove the first key from the cache list
        return keyToEvict;
    }
};