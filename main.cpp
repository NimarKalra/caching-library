#include <bits/stdc++.h>
#include "cache.h"
using namespace std;

int main(){
    Cache cache(4, EvictionPolicy::LRU);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);

    cache.printCache();
    cache.put(5, 5);
    cache.printCache();
    return 0;
}