#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "utilities.cpp"

void insertionSort(std::vector<int> &vec)
{
    for (size_t i = 1; i < vec.size(); i++)
    {
        int current = vec.at(i);
        int j = i - 1;
        while (j >= 0 && vec.at(j) > current)
        {
            vec.at(j + 1) = vec.at(j);
            j--;
        }
        vec.at(j + 1) = current;
    }
}
int main()
{
    srand(time(NULL));
    std::vector<int> numbers;
    int randomInt;

    for (size_t i = 0; i < 20; i++)
    {
        randomInt = std::rand() % 100;
        numbers.push_back(randomInt);
    }

    printVector(numbers);
    insertionSort(numbers);
    printVector(numbers);

    return 0;
}