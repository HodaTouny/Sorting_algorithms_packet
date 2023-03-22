
#ifndef SORTING_ALGORITHMS_PACKET_SORTLIB_H
#define SORTING_ALGORITHMS_PACKET_SORTLIB_H
#include <bits/stdc++.h>
using namespace std;


template<typename T>
void Selection_sort(T arr[],int n);


template<typename T>
void shell_sort(T arr[],int n);


template<typename T>
void count_sort(T arr[],int n);


template<typename T>
void bubble_sort(T arr[],int n);


template<typename T>
void quicksort(T arr[], int min, int n);
template<typename T>
void quick_sort(T arr[], int n);



template<typename T>
void mergesort(T arr[],int start,int end);
template<typename T>
void merge_sort(T arr[],int n);


template<typename T>
void insertion_sort(T arr[],int n);

#endif //SORTING_ALGORITHMS_PACKET_SORTLIB_H
