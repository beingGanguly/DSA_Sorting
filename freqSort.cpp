#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void freqSort(vector<int>& num_arr, int left, int right){
    if (left < right) {
        int mid = left + (right - left) / 2;

        freqSort(num_arr, left, mid);
        freqSort(num_arr, mid + 1, right);

        merge(num_arr, left, mid, right);
    }
}

int main() {
    vector<char> arr = {'%', '*', '$', '%', '*', '*'};
    vector<char> v;
    int n = arr.size();
    int count1=0, count2=0, count3=0;
    for(int i=0;i<n;i++){
        if(arr[i] == '%'){
            count1++;
        }
        else if(arr[i] == '*'){
            count2++;
        }
        else{
            count3++;
        }
    }
    vector<int>num_arr = {count1, count2, count3};
    int n1 = num_arr.size();
    
    freqSort(num_arr,0,n1-1);
    
    for (int i = 0; i < n1; i++)
        cout << num_arr[i] << " ";
    cout << endl;
    
    for(int i = 0; i<n1;i++){
        if(num_arr[i] == 1){
            v.push_back({'$'});
        }
        if(num_arr[i] == 2){
            v.push_back({'%'});
            v.push_back({'%'});
        }
        if(num_arr[i] == 3){
            v.push_back({'*'});
            v.push_back({'*'});
            v.push_back({'*'});
        }
    }
    cout<<"The sorted array:"<<endl;
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}