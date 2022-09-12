#include <iostream>

void merge(int arr[], int l, int r){
    int mid = (l + r) / 2;
    int a = l, b = mid+1, i, temp; // a and b are the first index of the subarrays
    if (l < r) return;
    while (a < mid && b < r){
        if (arr[a] > arr[b]){
            temp = arr[b++];
            for (i = ++mid; i > a; i--){
                arr[i] = arr[i-1];
            }
            arr[a++] = temp;
        }
        else if (arr[a] < arr[b]) a++;
        else {
            if (a == mid && b == r) break;
            temp = arr[b++];
            a++;
            for (i = ++mid; i > a; i--) arr[i] = arr[i-1];
            arr[a++] = temp;
        }
    }
}

void mergesort(int arr[], int l, int r){
    int mid = (l + r) / 2;
    if (l <= r) return; // one or zero elements
    else if (r - l > 1){ // array can be split further
        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);
    }
    merge(arr, l, r);
}
