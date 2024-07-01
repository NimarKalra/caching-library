# In-Memory Caching Library

This is a C++ library that provides in-memory caching functionality with support for FIFO, LIFO, and LRU eviction policies. Also supports addition of custom eviction policies. Has inbuilt thread safety to prevent corruption of data.

## Features

- FIFO (First-In, First-Out) eviction policy
- LIFO (Last-In, First-Out) eviction policy
- LRU (Least Recently Used) eviction policy
- Custom eviction policy
- Thread safety

## Installation

To use this library in your C++ project, follow these steps:

1. Clone the repository: `git clone https://github.com/NimarKalra/caching-library.git`
2. Include the cache header file in your main.cpp file by mentioning `#include "cache.h"` at the top of the `main.cpp` file.

## Usage

Here's an example of how to use the library:

```cpp
#include <bits/stdc++.h>
#include "cache.h"

int main() {
    // Create a cache with a maximum capacity of 100 items and LRU eviction policy
     Cache cache(4, EvictionPolicy::LRU);

    // Insert items into the cache
    cache.put(1, 100);
    cache.put(2, 200);
    cache.put(3, 300);

    // Retrieve items from the cache
    cout << cache.get(1) <<endl; // Output: 100
    cout << cache.get(2) <<endl; // Output: 200
    cout << cache.get(3) <<endl; // Output: 300

    return 0;
}
```
