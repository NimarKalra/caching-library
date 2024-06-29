# In-Memory Caching Library

This is a C++ library that provides in-memory caching functionality with support for FIFO, LIFO, and LRU eviction policies.

## Features

- FIFO (First-In, First-Out) eviction policy
- LIFO (Last-In, First-Out) eviction policy
- LRU (Least Recently Used) eviction policy

## Installation

To use this library in your C++ project, follow these steps:

1. Clone the repository: `git clone https://github.com/your-username/caching-library.git`
2. Include the necessary header files in your project.
3. Link against the library during compilation.

## Usage

Here's an example of how to use the library:

```cpp
#include <iostream>
#include "caching_library/cache.h"

int main() {
    // Create a cache with a maximum capacity of 100 items and LRU eviction policy
    Cache<int, std::string> cache(100, EvictionPolicy::LRU);

    // Insert items into the cache
    cache.insert(1, "Value 1");
    cache.insert(2, "Value 2");
    cache.insert(3, "Value 3");

    // Retrieve items from the cache
    std::cout << cache.get(1) << std::endl; // Output: "Value 1"
    std::cout << cache.get(2) << std::endl; // Output: "Value 2"
    std::cout << cache.get(3) << std::endl; // Output: "Value 3"

    return 0;
}
```

## Contributing

Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

## License

This library is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
