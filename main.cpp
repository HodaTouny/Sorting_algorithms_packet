#include <bits/stdc++.h>
#include "sortlib.cpp"
#include "generating.cpp"
using namespace std;

int main() {
    int size_200 = 200;
    int * arr_200 = generateRandomArray<int>(0,10000,size_200);

    int size_500 = 500;
    char * arr_500 = generateRandomArray<char>('a','z',size_500);

    int size_1000 = 1000;
    int * arr_1000 = generateRandomArray<int>(0,10000,size_1000);

    int size_5000 = 5000;
    int * arr_5000 = generateRandomArray<int>(0,10000,size_5000);

    int size_10000 = 10000;
    int * arr_10000 = generateRandomArray<int>(0,10000,size_10000);

    int size_20000 = 20000;
    int * arr_20000 = generateRandomArray<int>(0,10000,size_20000);

    int size_50000 = 50000;
    int * arr_50000 = generateRandomArray<int>(0,10000,size_50000);


    quick_sort(arr_50000,0,size_50000-1);
    print(arr_50000,size_50000);
    return 0;
}
