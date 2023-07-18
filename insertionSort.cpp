#include <iostream>
using namespace std;

void insertionSort(int array[], int size) {
  for (int i = 1; i < size; i++) {
    int key = array[i];
    int j = i - 1;
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}
int main() {
    int arr[]={10,45,3,23,56,67,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    insertionSort(arr,n);
    cout<<"Sorted numbers:";
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}