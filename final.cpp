#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>

using namespace std::chrono;

// Declare S
int S = 10;

// The return types of sort methods are interger to save the number of key comparison
int insertSort(int arr[], int arrSize, int firstIndex, int lastIndex);
int mergeSort(int arr[], int arrSize, int firstIndex, int lastIndex);
int mergeInsertSort(int arr[], int arrSize, int firstIndex, int lastIndex);
void merge(int arr[], int arrSize, int firstIndex, int lastIndex);
void printArray(int arr[], int arrSize);

// Insertion Sort
void insertSort(int arr[], int arrSize, int firstIndex, int lastIndex)
{
    int i, j, temp;
    int count = 0;
    for (int i = firstIndex; i < lastIndex; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}

// Merge Sort
int mergeSort(int arr[], int arrSize, int firstIndex, int lastIndex)
{
    int count = 1, count1, count2;
    int mid = (firstIndex + lastIndex) / 2;
    if (lastIndex - firstIndex <= 0)
    {
        return 0;
    }
    else /*if(lastIndex - firstIndex > 1)*/
    {
        count1 = mergeSort(arr, firstIndex, mid);
        count2 = mergeSort(arr, mid + 1, lastIndex);
    }
    merge(arr, firstIndex, lastIndex);

    count = count1 + count2;
    return count;
}

void merge(int arr[], int arrSize, int firstIndex, int lastIndex)
{
    int mid = (firstIndex + lastIndex) / 2;
    int i, j;
    // creating temp array
    int leftSize = mid - firstIndex + 1;
    int rightSize = lastIndex - mid;

    int leftArr[leftSize];
    int rightArr[rightSize];
    // populating array
    for (i = 0; i < leftSize; i++)
    {
        leftArr[i] = arr[i + firstIndex];
    }
    for (j = 0; j < rightSize; j++)
    {
        rightArr[j] = arr[j + mid + 1];
    }
    i = 0, j = 0;
    int x = firstIndex;
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[x] = leftArr[i];
            i++;
        }
        else
        {
            arr[x] = rightArr[j];
            j++;
        }
        x++;
    }
    // this is after either one of the subarr ends, we populate the remaining sorted array
    while (i < leftSize)
    {
        arr[x] = leftArr[i];
        i++;
        x++;
    }
    while (i < leftSize)
    {
        arr[x] = rightArr[j];
        j++;
        x++;
    }
}

// MergeInsert Sort
void mergeInsertSort(int arr[], int arrSize, int firstIndex, int lastIndex)
{
    int count = 1, count1, count2;
    int mid = (firstIndex + lastIndex) / 2;
    if (lastIndex - firstIndex <= 0)
    {
        return 0;
    }
    // Use merge sort if size of each sub-array is larger than S
    else if (lastIndex - firstIndex > 2 * S)
    {
        count1 = mergeSort(arr, arrSize, firstIndex, mid);
        count2 = mergeSort(arr, arrSize, mid + 1, lastIndex);
    }
    // Use insertion sort if size of each sub-array is equal or smaller than S
    else
    {
        count1 = insertSort(arr, arrSize, firstIndex, mid);
        count2 = insertSort(arr, arrSize, mid + 1, lastIndex);
    }
    merge(arr, firstIndex, lastIndex);

    count = count1 + count2;
    return count;
}

// Print & Check
void printArray(int arr[], int arrSize)
{
    printf("Array %d: ", arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        if ((i > 0) && (arr[i] < arr[i - 1]))
        {
            printf("\n ERROR!!! \n") return;
        }
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    // PLOTTING - vary array length (will count the number of key comparisons for plotting)
    long start = 1000;
    long end = 1100;
    int keyCompare[100];
    int count=0;
    for (int n = start; n < end; n++)
    {
        // Generate random array of size n
        int a[n];
        for (int j = 0; j < n; j++)
            a[j] = rand() % 1000;

        // --SORT--
        // TIMING - start
        // auto start = high_resolution_clock::now();
        keyCompare[count++] = mergeSort(a, n, 0, n - 1);
        // TIMING - end
        // auto stop = high_resolution_clock::now();
        // End timing, measure the duration
        // auto duration = duration_cast<microseconds>(stop - start);
        // printf("InsertSort took %f Seconds!\n",duration.count());

        // Print & Check
        //printArray(arr, arrSize);
    }

    for (int i = 0; i < 100; i++)
        print("%d,", keyCompare[i]);

    return 0;
}
