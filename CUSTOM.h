#include <iostream>
#include <unordered_map>
#include <list>
#include <memory>
using namespace std;


class CUSTOMPolicy : public EvictionStrategy {
public:
    void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) override {
        // add custom access logic here
    }

    int evictKey(list<int>& cacheList) override {
        // add custom eviction logic here
        return -1;  
    }
};