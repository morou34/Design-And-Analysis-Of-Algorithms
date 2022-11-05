#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <tuple>
#include "utilities.cpp"

std::pair<int, int> minMax(std::vector<int> &vec, int l, int r)
{
    if (l == r)
        return std::make_pair(vec.at(l), vec.at(l));

    else
    {

        int min1{0}, min2{0}, max1{0}, max2{0};
        int mid = (l + r) / 2;
        std::tie(min1, max1) = minMax(vec, l, mid);
        std::tie(min2, max2) = minMax(vec, mid + 1, r);

        if (min1 > min2)
            min1 = min2;

        if (max1 < max2)
            max1 = max2;
        return std::make_pair(min1, max1);
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    std::vector<int> numbers;
    int randomInt, min, max;

    for (size_t i = 0; i < 20; i++)
    {
        randomInt = std::rand() % 100;
        numbers.push_back(randomInt);
    }

    printVector(numbers);

    std::tie(min, max) = minMax(numbers, 0, numbers.size() - 1);
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}
