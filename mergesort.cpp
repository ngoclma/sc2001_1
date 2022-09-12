#include <iostream>

void merge(int arr[], int l, int r) {
  int mid = (l + r) / 2;
  int a = l, b = mid + 1, i,
      temp; // a and b are the first index of the subarrays
  if (r <= l) {
    return;
  }
  while (a <= mid && b <= r) {
    if (arr[a] > arr[b]) {
      temp = arr[b++];
      for (i = ++mid; i > a; i--) {
        arr[i] = arr[i - 1];
      }
      arr[a++] = temp;
    } else if (arr[a] < arr[b]) {
      a++;
    } else {
      if (a == mid && b == r) {
        break;
      }
      temp = arr[b++];
      a++;
      for (i = ++mid; i > a; i--) {
        arr[i] = arr[i - 1];
      }
      arr[a++] = temp;
    }
  }
}

void mergesort(int arr[], int l, int r) {
  int mid = (l + r) / 2;
  if (r - l <= 0) {
    return;
  }                     // one or zero elements
  else if (r - l > 1) { // array can be split further
    mergesort(arr, l, mid);
    mergesort(arr, mid + 1, r);
  }
  merge(arr, l, r);
}

int main() {
  // test arr
  int arr[] = {12, 31, 25, 8, 32, 17, 40, 42};

  mergesort(arr, 0, 7);

  for (int i = 0; i < 8; i++) {
    std::cout << arr[i] << ' ';
  }
  return 0;
}
