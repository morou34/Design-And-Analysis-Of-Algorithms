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


void merge(std::vector<int> &vec, int l, int m, int r)
{

    int i{l}, j{m + 1};
    std::vector<int> temp;
    while (i <= m && j <= r)
    {
        if (vec.at(i) <= vec.at(j))
        {
            temp.push_back(vec.at(i));
            i++;
        }
        else
        {
            temp.push_back(vec.at(j));
            j++;
        }
    }
    while (i <= m)
    {
        temp.push_back(vec.at(i));
        i++;
    }

    while (j <= r)
    {
        temp.push_back(vec.at(j));
        j++;
    }

    for (int p{l}, s{0}; s < temp.size(); p++, s++)
    {
        vec.at(p) = temp.at(s);
    }
}

void mergeSort(std::vector<int> &vec, int l, int r)
{
    if (l >= r)
        return ;
        
        int m = (l + r) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
}

int main(int argc, char const *argv[])
{
    std::vector<int> prices{42, 53, 13, 53, 64, 32, 14, 57, 87, 32, 65, 37};
    printData(prices);

    mergeSort(prices, 0, prices.size() - 1);

    printData(prices);

    return 0;
}
