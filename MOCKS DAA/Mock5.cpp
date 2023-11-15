#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    low++;
    int i = low;
    int j = high;
    while(true){
        if(i <= j && arr[i] <= pivot){
            i++;

        }
        if(i <= j && arr[j] > pivot){
            j--;

        }
        if(i <= j){
            swap(arr[i],arr[j]);

        }
        else{
            break;

        }
        
    }
    swap(arr[low-1],arr[j]);
    return j;

}

void quicksort(vector<int> &arr,int low,int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        quicksort(arr,low,pivot-1);
        quicksort(arr,pivot+1,high);


    }

}

int partition_r(vector<int> &arr,int low,int high){
    srand(3212);
    int random_index = low + rand()%(high-low+1);
    swap(arr[random_index],arr[low]);
    return partition(arr,low,high);
}

void quicksort_r(vector<int> &arr,int low,int high){
    if(low < high){
        int pivot = partition_r(arr,low,high);
        quicksort_r(arr,low,pivot-1);
        quicksort_r(arr,pivot+1,high);


    }

}

int main(){
    vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) {
        arr[i] = 10000 - i;
    }
    quicksort_r(arr, 0, arr.size() - 1);
    return 0;
}
