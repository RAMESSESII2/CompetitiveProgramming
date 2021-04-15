#include <algorithm>
#include<bits/stdc++.h>
#include <functional>
#define ll long long int
using namespace std;

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}
int n;
vector<int> arr;
vector<int> suff;
vector<int> pref;


int main()
{
    file_i_o();
    cin >> n;
    arr.resize(n);
    suff.resize(n);
    pref.resize(n);
    for( auto &x : arr ) cin >> x;
    pref[0] = 1;
    int ans=-987;
    for( int i = 1; i < n; i++ ){
        if( arr[i] > arr[i-1]){
            pref[i] = pref[i-1]+1;
        }
        else pref[i] = 1;
        ans = max(ans, pref[i]);
    }
    suff[n-1] = 1;
    for( int i = n-2; i >= 0; i-- ){
        if( arr[i] < arr[i+1]){
            suff[i] = suff[i+1]+1;
        }
        else suff[i] = 1;
        ans = max(ans, suff[i]);
    }
    for( int i = 1; i < n-1; i++ ){
        if( arr[i-1] < arr[i+1]){
            ans = max(ans, pref[i-1]+suff[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}

