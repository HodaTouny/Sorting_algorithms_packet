#include <bits/stdc++.h>
#include "sortlib.cpp"
#include "generating.cpp"
using namespace std;

int main() {
    int size = 100;
    int * arr = generateRandomArray<int>(0,100,size);
    print(arr,size);

    return 0;
}
