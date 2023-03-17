#include <bits/stdc++.h>
#include "sortlib.cpp"
#include "generating.cpp"
using namespace std;

int main() {
    int size = 100;
    int * arr = generateRandomArray<int>(0,100,size);
    print(arr,size);
    cout<<endl;
    Selection_sort(arr,size);
    print(arr,size);
    int size2 = 1000;
    int * arr2 = generateRandomArray<int>(0,1000,size2);
    print(arr2,size2);
    cout<<endl;
   shell_sort(arr2,size2);
    print(arr2,size2);
cout<<endl;
int arr3[]={4,6,1,2,50,0,4};
    shell_sort(arr3,7);
    print (arr3,7);

    return 0;
}
