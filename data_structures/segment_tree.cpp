#include<bits/stdc++.h>
/* #include<iostream> */
/* #include<stdlib.h> */
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode){
    if(start==end){
        tree[treeNode] = arr[start];
        return;
    }

    int mid = (start + end)/2;

    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);

    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(int *arr, int *tree, int start, int end, int treeNode, int index, int val){
    if (start == end){
        arr[index] = val;
        tree[treeNode] = val;
        return;
    }
    int mid = (start + end)/2;
    if (index>mid){
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, index, val);
    }
    else{
        updateTree(arr, tree, start, mid, 2*treeNode, index, val);
    }
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int query(int *tree, int start, int end, int treenode, int left, int right){
    //Completely outside the given range
    if (start > right || end < left){
        return 0;
    }
    //Completely inside the given range
    if (start >= left && end <= right){
        return tree[treenode];
    }
    //Partially inside and outside the given range
    int mid = (start+end)/2;
    int ans1 = query(tree, start, mid, 2*treenode, left, right);
    int ans2 = query(tree, mid+1, end, 2*treenode+1, left, right);
    return ans1+ans2;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int *tree = new int[19];

    buildTree(arr, tree, 0, 8, 1);

    for(int i=1; i<18; i++)
        cout << tree[i] << endl;

    updateTree(arr, tree, 0, 8, 1, 1, 5);

    for(int i=1; i<19; i++)
        cout << tree[i] << endl;
    cout << "till"<<endl;
    int ans = query(tree, 0, 8, 1, 2, 4);
    cout << "SUM btw 2-4: "<< ans<<endl;

}
