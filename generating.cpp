#include "generating.h"
template<typename T>
T* generateRandomArray(T min_val, T max_val, int size) {
    T *randArray = new T[size];
    for(int i=0;i<size;i++)
        randArray[i] = (T) rand() % (max_val - min_val + 1) + min_val;

    return randArray;
}
template<typename T>
void print(T*arr, int size){
    for(int i=0;i<size;i++){
        if(i<size-1) {
            cout << arr[i] << " - ";
        }else{
            cout<<arr[i];
        }
    }
    cout<<"\n";
}