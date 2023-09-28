#include <iostream>
#include <vector>
#include <cstdlib> // for creating random numbers used in stress test
using namespace std;

long long MaximumPairwiseProduct(std::vector<int> &numbers)
{
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((long long)numbers[i] * numbers[j] > result)
            {
                result = (long long)numbers[i] * numbers[j];
            }
        }
    }

    return result;
}

long long MaximumPairwiseProductUsingMaxPairs(std::vector<int> &numbers)
{
    long long result = 0;
    int max1Index = -1, max2Index = -1, n = numbers.size();
    for (int i = 0; i < n; i++)
    {
        if (max1Index == -1 || (numbers[i] > numbers[max1Index]))
        {
            max1Index = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (max1Index != i && (max2Index == -1 || (numbers[i] > numbers[max2Index])))
        {
            max2Index = i;
        }
    }

    result = numbers[max1Index] * numbers[max2Index];

    return result;
}

int main()
{
    // stress test
    // while (true)
    // {
    //     int n = rand() % 100 + 2;
    //     cout << "n : " << n << endl;
    //     vector<int> numbers(n);
    //     for (int i = 0; i < n; i++)
    //     {
    //         numbers[i] = rand() % 100000;
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << numbers[i] << ' ';
    //     }
    //     cout << endl;
    //     long long res1 = MaximumPairwiseProduct(numbers);
    //     long long res2 = MaximumPairwiseProductUsingMaxPairs(numbers);
    //     if(res1 != res2)
    //     {
    //         cout << "Wrong Matching: " << res1 << ' ' << res2 << endl;
    //         break; 
    //     }
    //     else
    //     {
    //         cout << "OK!" << endl;
    //     }

    // }
    // end of stress test

    // main program
    int n = 0;
    long long max = 0;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    // max = MaximumPairwiseProduct(numbers);
    max = MaximumPairwiseProductUsingMaxPairs(numbers);

    std::cout << "Maximum using iterations : " << max << std::endl;
    // end of main program

    return 0;
}