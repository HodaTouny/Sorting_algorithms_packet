#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

namespace sortlib{

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



    template<class T>
    void insertion_sort(T arr[], int n)
    {
        int j;
        T temp;

        for (int i = 1; i < n; ++i)
        {

            temp = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = temp;

        }
    }



    template<class T>
    void Merge(T arr[], int start, int end)
    {

        int z, x, y, mid;
        vector<T> temp(end -start + 1);
        mid = (start + end) / 2;
        z = 0;
        x = start;
        y = mid + 1;

        while (x <= mid && y <= end)
        {
            if (arr[x] < arr[y])
            {
                temp[z] = arr[x];
                ++x, ++z;
            }
            else
            {
                temp[z] = arr[y];
                ++y, ++z;
            }
        }

        while (x <= mid)
        {
            temp[z] = arr[x];
            ++x, ++z;
        }

        while (y <= end)
        {
            temp[z] = arr[y];
            ++y, ++z;
        }
        for (int i = start; i <= end; ++i)
        {
            arr[i] = temp[i - start];
        }

    }
    template<typename T>
    void MergeSort(T arr[], int start, int end)
    {

        if (start < end)
        {
            int mid = (start + end) / 2;
            MergeSort(arr, start, mid);
            MergeSort(arr, mid + 1, end);
            Merge(arr, start, end);
        }

    }

    template<class T>
    void merge_sort(T arr[], int n){
        MergeSort(arr,0,n);
    }

    template <typename T>
    double time_execution(void (*sorting_algorithm)(T*, T), T* arr, int n) {
        using std::chrono::duration;
        using std::chrono::milliseconds;
        using std::chrono::high_resolution_clock;
        using std::chrono::duration_cast;
        auto t1 = high_resolution_clock::now();
        sorting_algorithm(arr,n);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        return ms_double.count();
    }


    template <class T>
    T *random_array(T arr[], int n, T min_val, T max_val) {
        srand(time(0));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (max_val - min_val + 1) + min_val;
        }
        return arr;
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


}

using namespace sortlib;
void calculate_time (int n){
    int arr1[n];
    random_array(arr1,n,0,500000);
    double insertion_sort_time = time_execution(insertion_sort, arr1 , n );
    cout << "Insertion sort: " <<  fixed << setprecision(3) << insertion_sort_time  <<" ms " << endl;

    random_array(arr1,n,0,500000);
    double selection_sort_time = time_execution(Selection_sort, arr1 , n );
    cout << "Selection sort: " <<  fixed << setprecision(3) << selection_sort_time  <<" ms " << endl;

    random_array(arr1,n,0,500000);
    double bubble_sort_time = time_execution(bubble_sort, arr1 , n );
    cout << "Bubble sort: " <<  fixed << setprecision(3) << bubble_sort_time  <<" ms "  << endl;

    random_array(arr1,n,0,500000);
    double merge_sort_time = time_execution(merge_sort, arr1 , n );
    cout << "Merge sort: " <<  fixed << setprecision(3) << merge_sort_time  <<" ms " << endl;

    random_array(arr1,n,0,500000);
    double shell_sort_time = time_execution(shell_sort, arr1 , n );
    cout << "Shell sort: " <<  fixed << setprecision(3) << shell_sort_time  <<" ms " << endl;

    random_array(arr1,n,0,500000);
    double quick_sort_time = time_execution(quick_sort, arr1 , n );
    cout << "Quick sort: " <<  fixed << setprecision(3) << quick_sort_time  << " ms " << endl;

    random_array(arr1,n,0,500000);
    double count_sort_time = time_execution(count_sort, arr1 , n );
    cout << "Count sort: " <<  fixed << setprecision(3) << count_sort_time  <<" ms "<< endl;
}

int main(){
    //calculate_time(500);
    int size = 200;
    int * arr = random_array(arr,size,0,12000);
    sortlib:: insertion_sort(arr,size);
    print(arr,size);

    return 0;
}