#include <iostream>
#include <vector>
#include <string>

// Print a vector of any type;
template <typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "[ ";
    for (const T &val : vec)
        std::cout << val << " ";
    std::cout << "]\n";
}


