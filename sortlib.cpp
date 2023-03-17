#include "sortlib.h"
template<typename T>
void Selection_sort(T arr[],int n){
    //int min;
    //min=arr[0];
    for(int i=0;i<n-1;i++){
       int min=i;
      // min=arr[i];
       for (int j=i+1;j<n;j++) {
           if (arr[j] < arr[min]) {
               min = j;
           }
       }

           if (min!=i){
              swap(arr[i],arr[min]);

           }

       }
    }
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
            }
        }
    }
}