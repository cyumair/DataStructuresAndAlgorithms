#include <iostream>
#include <math.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;

stack<string> methodstack;
//------------------------------------------------------------
//////////////////BUBBLE SORT THROUGH ITERATION///////////////////
void bubbleSort(int arr[], int size){
    for(int i = size - 1; i >= 0; i--){
        for(int j = 0; j < i; j++) {
            if(arr[j] <arr[j+1]){
                int high = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = high;
            }
        }
    }
}

//////////////////BUBBLE SORT THROUGH RECURSION/////////////////////
void RecursiveBubbleSort(int arr[], int i){
    if (i == 0){
        return;
    }
    else{
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]){
                int high = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = high;
            }
        }
        RecursiveBubbleSort(arr, i-1);
    }
}

//-------------------------------------------------------------------------

int smallestIndex(int arr[], int start, int end){
    int smallest = start;
    for(int i = start + 1; i < end; i++){
        if (arr[i] < arr[smallest]){  
            smallest = i;
        }
    }
    return smallest;
}

//////////////////SELECTION SORT THROUGH ITERATION/////////////////////
void selectionSort(int* arr, int size){
    for(int i = 0; i < size-1; i++){
        int smallestindex = smallestIndex(arr, i, size);
        if(arr[i] > arr[smallestindex]){
            int smallest = arr[smallestindex];
            arr[smallestindex] = arr[i];
            arr[i] = smallest;
        }
    }

}

//////////////////SELECTION SORT THROUGH RECURSION/////////////////////
void RecursiveSelectionSort(int arr[], int size, int index){
    if(index == size){
        return;
    }
    else{
        int smallestindex = smallestIndex(arr, index, size);
        if(arr[index] > arr[smallestindex]){
            int smallest = arr[smallestindex];
            arr[smallestindex] = arr[index];
            arr[index] = smallest;
        }
        RecursiveSelectionSort(arr, size, index+1);
    }
}

//-----------------------------------------------------------------------
//////////////////INSERTION SORT THROUGH ITERATION/////////////////////
void insertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int current = arr[i];
        int prev = i - 1;

        while(arr[prev] > current && prev >= 0){
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = current;
    }
}
//////////////////INSERTION SORT THROUGH RECURSION/////////////////////
void RecursiveInsertionSort(int arr[], int size, int i){
    if(i == size){
        return;
    }
    else{
        int current = arr[i];
        int prev = i - 1;
        while(arr[prev] > current && prev >= 0){
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }
        arr[prev + 1] = current;
        RecursiveInsertionSort(arr, size, i + 1);
    }
}

//----------------------------------------------------------------------------------
///////////////////MERGE-SORT ALGORITHM////////////////////
void merge(int arr[], int left, int mid, int right){
    cout << "left: " << left << ", right: " << right << ", mid: " << mid << endl;
    int first1 = left;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = right;
    int temp[right+1];
    int index = first1;
    while(index <= right){
        if(first1 > mid){
            while(first2 <= right){
                temp[index] = arr[first2];
                first2 ++;
                index++;
            }
        }

        else if(first2 > right){
            while(first1 <= mid){ 
                temp[index] = arr[first1];
                first1++;
                index++;
            }
        }

        else{
            if(arr[first1] < arr[first2]){
                temp[index] = arr[first1];
                first1++;
            }
            else{
                temp[index] = arr[first2];
                first2++;
            }
            index++;
        }
    }

    for (int i = left; i <= right; i++){
        arr[i] = temp[i];
    }
    
}


void mergeSort(int arr[], int left, int right){
    if(left < right) {
        //cout << "something is going on" << endl;
        int mid = (left + (right-1)) / 2;
        mergeSort(arr, left, mid);
        //cout << "left: " << left << ", right: " << right << endl;
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

}

int main(){
    
    int arr[] = {4,3,2,1,0,12,13,55,22,6};  
    int size = sizeof(arr)/sizeof(arr[0]);
    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size-1);
    // RecursiveInsertionSort(arr, size, 1);
    // mergeSort(arr, 0, size-1);
    // RecursiveSelectionSort(arr, size, 0);
    RecursiveBubbleSort(arr, size - 1);
    cout << "completed sucessfully" << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << ", " ;
    }
    
};