#include <iostream>
#include <math.h>
using namespace std;


int findRecursively(int arr[],  int item, int left, int right);
int BinarySearch(int arr[], int size, int item);
int main(){
    int arr[] = {1,2,3,4,5};  
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << findRecursively(arr, 4, 0, size-1) << endl;
    cout << BinarySearch(arr, size, 4) << endl;
    cout << "finished" << endl;
};

//////////////////BINARY SEARCH THROUGH RECURSION///////////////////
int findRecursively(int arr[], int item, int left, int right){
    if(right < left){
        return -1;
    }
    else{
        int mid = (left + right) / 2;
        cout << mid << endl;
        if(arr[mid] == item){
            return mid;
        }
        else{
            if(arr[mid] < item){
                return findRecursively(arr, item, mid+1, right);
            }   
            else{
            // cout << "executed" << endl;
            return findRecursively(arr, item, left, mid-1);
                
            }
        }
    }
};

//////////////////BINARY SEARCH THROUGH ITERATION///////////////////
int BinarySearch(int arr[], int size, int item){
    int left = 0;
    int right = size;
    while(!(right < left)){
        int mid = (left + right)/2;
        if(arr[mid] == item){
            return mid;
        }
        else{
            if(item < arr[mid]){
                right = mid-1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    return -1;
}