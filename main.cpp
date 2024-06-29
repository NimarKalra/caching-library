#include <bits/stdc++.h>
#include "cache.h"



using namespace std;

int main(){
    Cache<int, int> cache(4, EvictionPolicy::LRU);
    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);

    cout << cache.get(1) << endl; // Output: 1
    cout << cache.get(2) << endl; // Output: 2
    cout << cache.get(3) << endl; // Output: 3
    cout << cache.get(4) << endl; // Output: 4
    cache.put(5, 5);
    cout << cache.get(1) << endl; // Output: Key does not exist in the cache

    return 0;
}