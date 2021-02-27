#include <iostream>
using namespace std;

int LinearSearch(int arr[], int item, int size);
int recursiveLinearSearch(int arr[], int item, int index);

int main(){
    int arr[] = {1,2,3,4,5};
    cout << recursiveLinearSearch(arr, 2, 0) << endl;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << LinearSearch(arr, 3, size) << endl;
    
};

//////////////////LINEAR SEARCH THROUGH ITERATION///////////////////
int LinearSearch(int arr[], int item, int size){
    for(int i = 0; i < size; i++){
            if (arr[i] == item){
                return i;
            }
    }
    return -1;
}

//////////////////LINEAR SEARCH THROUGH RECURSION///////////////////
int recursiveLinearSearch(int arr[], int item, int index){
    if(index == 5){
        return -1;
    }
    else if(item == arr[index]){
        return index;
    }
    else{
        return recursiveLinearSearch(arr, item, index + 1);
    }
}
