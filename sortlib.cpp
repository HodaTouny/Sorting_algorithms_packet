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

template<typename T>
void quicksort(T arr[],int min,int n){
    if(min>=n){
        return;
    }
    int piv = arr[min];
    int i = min;
    for(int j=min;j<=n;j++){
        if(arr[j]<piv){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[min]);

    int pivot = i;
    quicksort(arr, min, pivot - 1);
    quicksort(arr, pivot + 1, n);

}

template<typename T>
void quick_sort(T arr[],int n){
    quicksort(arr,0,n-1);
}


//template <typename T>
//double time_execution(void (*sorting_algorithm)(T*, T), T* arr, int n) {
//    using std::chrono::duration;
//    using std::chrono::milliseconds;
//    using std::chrono::high_resolution_clock;
//    using std::chrono::duration_cast;
//    auto t1 = high_resolution_clock::now();
//    sorting_algorithm(arr,n);
//    auto t2 = high_resolution_clock::now();
//    /* Getting number of milliseconds as a double. */
//    duration<double, std::milli> ms_double = t2 - t1;
//    return ms_double.count();
//}
//template <class T>
//void randomization (T arr[] , int n)
//{
//    srand(time(0));
//    for (int i = 0; i < n; i++) {
//        arr[i] = rand();
//    }
//}
//void functions (int n){
//    int arr1[n];
// //    randomization(arr1,n);
// //    double insertion_sort_time = time_execution(insertion_sort, arr1 , n );
// //    cout << "Insertion sort execution time: " <<  fixed << setprecision(5) << insertion_sort_time  <<" Milliseconds" << endl;
//
//    randomization(arr1,n);
//    double selection_sort_time = time_execution(Selection_sort, arr1 , n );
//    cout << "Selection sort execution time: " <<  fixed << setprecision(5) << selection_sort_time  <<" Milliseconds" << endl;
//
//    randomization(arr1,n);
//    double bubble_sort_time = time_execution(bubble_sort, arr1 , n );
//    cout << "Bubble sort execution time: " <<  fixed << setprecision(5) << bubble_sort_time  <<" Milliseconds" << endl;
//
// //    randomization(arr1,n);
// //    double merge_sort_time = time_execution(merge_sort, arr1 , n );
// //    cout << "Merge sort execution time: " <<  fixed << setprecision(5) << merge_sort_time  <<" Milliseconds" << endl;
//
//    randomization(arr1,n);
//    double shell_sort_time = time_execution(shell_sort, arr1 , n );
//    cout << "Shell sort execution time: " <<  fixed << setprecision(5) << shell_sort_time  <<" Milliseconds" << endl;
//
// //    randomization(arr1,n);
// //    double quick_sort_time = time_execution(quick_sort, arr1 ,0, n );
// //    cout << "Quick sort execution time: " <<  fixed << setprecision(5) << quick_sort_time  <<" Milliseconds" << endl;
//
//    randomization(arr1,n);
//    double count_sort_time = time_execution(count_sort, arr1 , n );
//    cout << "Count sort execution time: " <<  fixed << setprecision(5) << count_sort_time  <<" Milliseconds" << endl;
//}