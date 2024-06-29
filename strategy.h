#include <list>
#include <unordered_map>
using namespace std;

class EvictionStrategy {
public:
    virtual ~EvictionStrategy() = default;
    virtual void keyAccessed(list<int>& cacheList, unordered_map<int, pair<int,list<int>::iterator>>& cacheMap, int key) = 0;
    virtual int evictKey(list<int>& cacheList) = 0;
};