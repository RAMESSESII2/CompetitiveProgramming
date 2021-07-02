#include <array>
#include<bits/stdc++.h>
#include <type_traits>
using namespace std;

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for( int j = l; j < r; j++ ){
        if( arr[j] <= pivot ){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if( l < r ){
        int p = partition(arr, l, r);
        // cout << p << endl;
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
}

int main(){
    int n;
    cin >> n;
    // int *arr = (int *)malloc(n*sizeof(int));
    int arr[100];
    for(int i = 0; i < n; i++){
        cin >> *(arr+i);
    }
    quickSort(arr, 0, n-1);
    for( int i = 0; i < n ; i++ ) cout << arr[i] << " ";
}
