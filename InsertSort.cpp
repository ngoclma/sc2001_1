#include <iostream>

void insertSort(int arr[],int arrSize);
void mergeSort(int arr[], int firstIndex,int lastIndex);
void merge(int arr[], int firstIndex,int lastIndex);
void printArray(int arr[],int arrSize);


int main() {
    //test arr
    int arr[] = {12, 31, 25, 8, 32, 17, 40, 42};
    //get size of array
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    //call inserSort function
    insertSort(arr,arrSize);
   // mergeSort(arr,0,arrSize-1);
    printArray(arr,arrSize);
    return 0;
}

void printArray(int arr[],int arrSize){
    for(int i = 0 ; i< arrSize ; i++){
        printf("%d ",arr[i]);
    }
}

void insertSort(int arr[],int arrSize){
        int i,j; //using sizeof in function doesnt work
        int temp;
        for(int i = 1; i< arrSize;i++){
            for(int j = i; j>0 ; j--){
                if(arr[j-1] > arr[j]){
                    temp = arr[j];  //swap
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
                else{
                    break;
                }
            }
        }
    }

void mergeSort(int arr[], int firstIndex,int lastIndex){
    
    int mid = (firstIndex+lastIndex)/2;
    if(lastIndex - firstIndex <= 0 ){
        return;
        }
    else /*if(lastIndex - firstIndex > 1)*/{

        mergeSort(arr, firstIndex, mid);
        mergeSort(arr, mid+1, lastIndex);
    }
    merge(arr, firstIndex, lastIndex);
}


void merge(int arr[], int firstIndex,int lastIndex){
    int mid = (firstIndex + lastIndex)/2;
    int i,j;
    //creating temp array
    int leftSize = mid - firstIndex + 1;
    int rightSize = lastIndex - mid;
    
    int leftArr[leftSize];
    int rightArr[rightSize];   
    //populating array
    for(i = 0;i<leftSize;i++){
        leftArr[i] = arr[i+firstIndex];
    }
    for(j = 0;j<rightSize;j++){
        rightArr[j] = arr[j+mid+1];
    }
    i =0,j=0;
    int x = firstIndex;
    while(i<leftSize && j<rightSize ){
        if(leftArr[i] <= rightArr[j]){
            arr[x] = leftArr[i];
            i++;
            
        } 
        else{
            arr[x] = rightArr[j];
            j++;
        }
        x++;
    }
    //this is after either one of the subarr ends, we populate the remaining sorted array
    while(i<leftSize){
        arr[x] = leftArr[i];
        i++;
        x++;
    }
    while(i<leftSize){
        arr[x] = rightArr[j];
        j++;
        x++;
    }
}