#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <stdio.h>

using namespace std::chrono;

// Declare S
int S = 10;

// The return types of sort methods are integer to save the number of key comparison
int insertSort(int arr[], int firstIndex, int lastIndex);
int mergeSort(int arr[], int firstIndex, int lastIndex);
int mergeInsertSort(int arr[], int firstIndex, int lastIndex);
int merge(int arr[], int firstIndex, int lastIndex);
void printArray(int arr[], int arrSize);

// Insertion Sort
int insertSort(int arr[], int firstIndex, int lastIndex)
{
  int i, j, temp;
  int c = 0;
  for (int i = firstIndex; i <= lastIndex; i++)
  {
    for (int j = i; j > 0; j--)
    {
      if (arr[j - 1] > arr[j])
      {
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        c++;
      }
      else
      {
        break;
      }
    }
  }
  return c;
}

// Merge Sort
int mergeSort(int arr[], int l, int r)
{
  int c = 0, c1 = 0, c2 = 0, c3 = 0;
  int mid = (l + r) / 2;
  if (r - l <= 0)
  {
    return 0;
  } // one or zero elements
  else if (r - l > 1)
  { // array can be split further
    c1 = mergeSort(arr, l, mid);
    c2 = mergeSort(arr, mid + 1, r);
  }
  c3 = merge(arr, l, r);
  c = c1 + c2 + c3;
  return c;
}

int merge(int arr[], int l, int r)
{
  int c = 0;

  int mid = (l + r) / 2;
  int a = l, b = mid + 1, i, temp;
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
int mergeInsertSort(int arr[], int firstIndex, int lastIndex)
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
    c1 = mergeSort(arr, firstIndex, mid);
    c2 = mergeSort(arr, mid + 1, lastIndex);
  }
  // Use insertion sort if size of each sub-array is equal or smaller than S
  else
  {
    c1 = insertSort(arr, firstIndex, mid);
    c2 = insertSort(arr, mid + 1, lastIndex);
  }
  c3 = merge(arr, firstIndex, lastIndex);

  c = c1 + c2 + c3;
  return c;
}

// Print & Check
void printArray(int arr[], int arrSize)
{
  printf("Array %d: ", arrSize);
  for (int i = 0; i < arrSize; i++)
  {
    if ((i > 0) && (arr[i] < arr[i - 1]))
    {
      printf("\n ERROR!!! \n");
      return;
    }
    else
      printf("%d ", arr[i]);
  }
  printf("\n");
}

int main()
{
  // PLOTTING - vary array length (will count the number of key comparisons for plotting)
  srand(unsigned(time(NULL)));
  long start = 1000;
  long end = 2000;
  int keyCompareInsert[1000], keyCompareMerge[1000], keyCompareInMe[1000];
  for (int j = 0; j < 1000; j++)
    keyCompareInsert[j] = keyCompareMerge[j] = keyCompareInMe[j] = 0;

  int i = 0;
  for (int n = start; n < end; n += 100)
  {
    // Generate random array of size n
    int a[n], b[n], c[n];
    // printf("Array size %d: ", n);
    for (int j = 0; j < n; j++)
    {
      a[j] = rand() % 1000;
      c[j] = b[j] = a[j];
      // printf("%d,", c[j]);
    }
    // printf("\n");

    // --SORT--
    // TIMING - start
    // auto start = high_resolution_clock::now();

    keyCompareInsert[i] = insertSort(a, 0, n - 1);
    keyCompareMerge[i] = mergeSort(b, 0, n - 1);
    keyCompareInMe[i++] = mergeInsertSort(c, 0, n - 1);

    /* printf("New a: ");
    for (int j = 0; j < i; j++)
        printf("%d,", a[j]);
    printf("\n");
    printf("New b: ");
    for (int j = 0; j < i; j++)
        printf("%d,", b[j]);
    printf("\n");
    printf("New c: ");
    for (int j = 0; j < i; j++)
        printf("%d,", c[j]);
    printf("\n");*/

    // TIMING - end
    // auto stop = high_resolution_clock::now();
    // End timing, measure the duration
    // auto duration = duration_cast<microseconds>(stop - start);
    // printf("InsertSort took %f Seconds!\n",duration.count());
  }

  printf("Insertion Sort:       ");
  for (int j = 0; j < i; j++)
    printf("%d,", keyCompareInsert[j]);
  printf("\n");
  printf("Merge Sort:           ");
  for (int j = 0; j < i; j++)
    printf("%d,", keyCompareMerge[j]);
  printf("\n");
  printf("Insertion Merge Sort: ");
  for (int j = 0; j < i; j++)
    printf("%d,", keyCompareInMe[j]);

  return 0;
}
