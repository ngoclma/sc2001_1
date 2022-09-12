#include <iostream>

void merge(int arr[], int l, int r, int *count){
  int mid = (l + r) / 2;
  int a = l, b = mid + 1, i, temp;
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
    (*count)++;
  }
}

void mergesorthelper(int arr[], int l, int r, int *count) {
  int mid = (l + r) / 2;
  if (r - l <= 0) {
    return;
  }                     // one or zero elements
  else if (r - l > 1) { // array can be split further
    mergesorthelper(arr, l, mid, count);
    mergesorthelper(arr, mid + 1, r, count);
  }
  merge(arr, l, r, count);
}

int mergesort(int arr[], int l, int r) {
  int count=0;
  mergesorthelper(arr, l, r, &count);
  return count;
}

int main() {
  // test arr
  int arr[] = {5,4,3,2,1};
  int cnt = mergesort(arr, 0, 4);

  for (int i = 0; i < 8; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n' << cnt;
  return 0;
}
