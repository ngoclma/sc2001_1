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
int merge(int arr[], int arrSize, int firstIndex, int lastIndex);
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
int mergesort(int arr[], int l, int r)
{
  int c = 0, c1 = 0, c2 = 0, c3 = 0;
  int mid = (l + r) / 2;
  if (r - l <= 0)
  {
    return 0;
  } // one or zero elements
  else if (r - l > 1)
  { // array can be split further
    c1 = mergesort(arr, l, mid);
    c2 = mergesort(arr, mid + 1, r);
  }
  c3 = merge(arr, l, r);
  c = c1 + c2 + c3;
  return c;
}

int merge(int arr[], int l, int r)
{
  int c = 0;

  int mid = (l + r) / 2;
  int a = l, b = mid + 1, i,
      temp; // a and b are the first index of the subarrays
  if (r <= l)
  {
    return 0;
  }
  while (a <= mid && b <= r)
  {
    if (arr[a] > arr[b])
    {
      c++;

      temp = arr[b++];
      for (i = ++mid; i > a; i--)
      {
        arr[i] = arr[i - 1];
      }
      arr[a++] = temp;
    }
    else if (arr[a] < arr[b])
    {
      c++;
      a++;
    }
    else
    {
      if (a == mid && b == r)
      {
        break;
      }
      temp = arr[b++];
      a++;
      for (i = ++mid; i > a; i--)
      {
        arr[i] = arr[i - 1];
      }
      arr[a++] = temp;
    }
  }

  return c;
}

// MergeInsert Sort
void mergeInsertSort(int arr[], int arrSize, int firstIndex, int lastIndex)
{
  int c = 0, c1 = 0, c2 = 0, c3 = 0;
  int mid = (firstIndex + lastIndex) / 2;
  if (lastIndex - firstIndex <= 0)
  {
    return 0;
  }
  // Use merge sort if size of each sub-array is larger than S
  else if (lastIndex - firstIndex > 2 * S)
  {
    c1 = mergeSort(arr, arrSize, firstIndex, mid);
    c2 = mergeSort(arr, arrSize, mid + 1, lastIndex);
  }
  // Use insertion sort if size of each sub-array is equal or smaller than S
  else
  {
    c1 = insertSort(arr, arrSize, firstIndex, mid);
    c2 = insertSort(arr, arrSize, mid + 1, lastIndex);
  }
  c3 = merge(arr, firstIndex, lastIndex);

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
  int count = 0;
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
    // printArray(arr, arrSize);
  }

  for (int i = 0; i < 100; i++)
    print("%d,", keyCompare[i]);

  return 0;
}
