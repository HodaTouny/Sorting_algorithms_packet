#include "sortlib.h"
template<typename T>
void Selection_sort(T arr[],int n){
    for(int i=0;i<n-1;i++){
       int min=i;
       for (int j=i+1;j<n;j++) {
           if (arr[j] < arr[min]) {
               min = j;
           }
       }
       if (min!=i){
          swap(arr[i],arr[min]);

}}}
template<typename T>
void shell_sort(T arr[],int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i-=gap){
                if(arr[i+gap]>arr[i]){
                    break;
                }
                else
                    swap(arr[i+gap],arr[i]);
}}}}

template<typename T>
void count_sort(T arr[], int n) {
    int max = 0;
    int min =0; //used for shifting the index to handle (-ve) values.
    T* final = new T[n];
    for(int k = 0; k < n; k++) {
        if((arr[k]) > max) {
            max = arr[k];
        }
        if(arr[k]<min){
            min = arr[k];
    }}
    max = max - min +1;
    int* array = new int[max];
    for(int i = 0; i < max; i++) {
        array[i] = 0;
    }
    for(int j = 0; j < n; j++) {
        array[arr[j]-min]++;
    }
    for(int i = 1; i < max; i++) {
        array[i] += array[i-1];
    }
    for(int i = n - 1; i >= 0; i--) {
        final[array[arr[i] - min]-1] = arr[i];
        array[arr[i]-min]--;
    }
    for(int i = 0; i < n; i++) {
        arr[i] = final[i];
    }
    delete[] array;
    delete[] final;
}
template<typename T>
/*bool x --> to make it optimized --> if the array sorted in any time there
is no need to complete the loops*/
void bubble_sort(T arr[],int n){
    for(int j=1;j<n-1;j++){
        bool x = false;
        for (int i = 0; i<n-1; i++) {
            if (arr[i] > arr[i + 1]){
                swap(arr[i], arr[i + 1]);
                x = true;
         }}
        if(!x){
            break;
        }
}}
//template<typename T>
//int sort_pivot(T arr[],int min,int max){
//    int piv = arr[min];
//    int i = min;
//    for(int j=min+1;j<=max;j++){
//        if(arr[j]<piv){
//            i++;
//            swap(arr[i],arr[j]);
//        }
//    }
//    swap(arr[i],arr[min]);
//    return i;
//
//}
//
//template<typename T>
//void quick_sort(T arr[],int min,int n){
//    if(min>=n){
//        return;
//    }
//        int pivot = sort_pivot(arr, min, n);
//        quick_sort(arr, min, pivot - 1);
//        quick_sort(arr, pivot + 1, n);
//
//}

template<typename T>
int sort_pivot(T arr[],int min,int max){
    int piv = arr[min];
    int i = min;
    for(int j=min;j<=max;j++){
        if(arr[j]<piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[min]);
    return i;

}

template<typename T>
void quick_sort(T arr[],int min,int n){
    if(min>=n){
        return;
    }
    int pivot = sort_pivot(arr, min, n);
    quick_sort(arr, min, pivot - 1);
    quick_sort(arr, pivot + 1, n);

}
