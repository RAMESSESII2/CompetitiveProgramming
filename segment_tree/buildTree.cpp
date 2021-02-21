#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <array>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define ff              first
#define ss              second
#define inf             1e18
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

#define print(dp, n); \
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl; 
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " ";}cout << endl;} 


typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
bool compare(int a, int b){
    return a>b;
}

void build(vi &tree, vi &arr, ll s, ll e, ll tidx){
    if(s == e){
        tree[tidx] = arr[s];
        return;
    }
    ll m = mid(s, e);
    ll left = 2*tidx;
    ll right = left +1;
    build(tree, arr, s, m, left);
    build(tree, arr, m+1, e, right);
    tree[tidx] = tree[left] + tree[right];
}

ll query(vi &tree, ll s, ll e, ll tidx, ll l, ll r){
    if( s>r or e<l){
        return 0;
    }
    if(s>=l and e<=r){
        return tree[tidx];
    }
    ll m = mid(s, e);
    ll left = query(tree, s , m, 2*tidx, l ,r);
    ll right = query(tree, m+1 , e, 2*tidx+1, l ,r);
    return left + right;
}

void update(vi &tree, vi &arr, ll s, ll e, ll tidx, ll ind, ll val){
    if(s==e){
        arr[s] = val;
        tree[tidx] = val;
        return;
    }
    ll m = mid(s, e);
    if( m>=ind){
        update(tree, arr, s, m, 2*tidx, ind, val);
    }
    else update(tree, arr, m+1, e, 2*tidx+1, ind, val);
    tree[tidx] = tree[2*tidx] + tree[2*tidx+1];
}

int main(){
    clock_t begin = clock();
    /* file_i_o(); */
    vi arr(5);
    arr ={1,2,3,4,5};
    vi tree(10,0);
    build(tree, arr, 0, 4, 1);
    print(tree, 9);
    cout << query(tree, 0, 4, 1, 1, 3) << endl;
    update(tree, arr, 0, 4, 1, 1, 6);
    print(arr, 4);
    
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


