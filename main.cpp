#include <bits/stdc++.h>
#include "sortlib.cpp"
#include "generating.cpp"
using namespace std;
//
//int main() {
//    int size_200 = 200;
//    int * arr_200 = generateRandomArray<int>(0,10000,size_200);
////
////    int size_500 = 500;
////    int * arr_500 = generateRandomArray<char>(0,500,size_500);
//
//    int size_1000 = 1000;
//    int * arr_1000 = generateRandomArray<int>(0,10000,size_1000);
//
//    int size_5000 = 5000;
//    int * arr_5000 = generateRandomArray<int>(0,10000,size_5000);
//
//    int size_10000 = 10000;
//    int * arr_10000 = generateRandomArray<int>(0,10000,size_10000);
//
//    int size_20000 = 20000;
//    int * arr_20000 = generateRandomArray<int>(0,10000,size_20000);
//
//    int size_50000 = 50000;
//    int * arr_50000 = generateRandomArray<int>(0,10000,size_50000);
//
//   (arr_200,0,199);
//    print(arr_200,size_200);
//
//
//
//}
#include <iostream>
#include <chrono>
#include <random>


int main()
{
    // Create a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100000);

    // Create an array of datasets
    int datasets[7] = {200, 500, 1000,5000, 10000, 20000, 50000};

    // Loop through each dataset size
    for (int i = 0; i < 7; i++)
    {
        int size = datasets[i];
        int *arr = new int[size];

        // Populate the array with random numbers
        for (int j = 0; j < size; j++)
        {
            arr[j] = dist(gen);
        }

        // Sort the array and calculate the running time
        auto start = std::chrono::high_resolution_clock::now();
        count_sort(arr, size); // call your sorting function from the package
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        // Print the running time for this dataset
        std::cout << "Dataset " << (i+1) << " (size " << size << "): " << duration.count() << " milliseconds\n";

        // Free the memory allocated for the array
        delete[] arr;
    }

    return 0;
}
