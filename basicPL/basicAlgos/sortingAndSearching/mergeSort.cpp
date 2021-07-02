#include<bits/stdc++.h>
#include <ratio>
using namespace std;

int n;
int *arr;

void merge(int l, int m, int r){
    int n1= m-l+1;
    int n2 = r-m;

    int la[n1], ra[n2];
    for( int i = 0; i < n1; i++){
        la[i] = arr[l+i];
    }
    for( int i = 0; i < n2; i++){
        ra[i] = arr[m+i+1];
    }
    int i = 0, j = 0;
    int k = l;
    while( i < n1 && j < n2 ){
        if( la[i] <= ra[j]){
            arr[k++] = la[i++];
        }
        else{
            arr[k++] = ra[j++];
        }
    }
    while( i < n1 ){
        arr[k++] = la[i++];
    }
    while( j < n2 ){
        arr[k++] = ra[j++];
    }

}

void mergeSort(int l, int r){
    if( l < r ){
        int m = l+ (r-l)/2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main(){
    cin >> n;
    arr = (int *)malloc(n*sizeof(int));
    for( int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSort(0, n-1);
    for( int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}
