#include <iostream>
#include <vector>
#include <string>
void printData(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (const int number : vec)
        std::cout << number << " ";
    std::cout << "]\n";
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
