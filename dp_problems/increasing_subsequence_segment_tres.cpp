/* You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one. */

/* A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. */
/* You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one. */

/* A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. */

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
#define inf             1e18
#define mid(l, r)       (l + (r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<=b; i++)
#define loopr(i, a, b)  for(int i=(a); i>=b; i--)

typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;

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
    loop(i, 0, n){cout << dp[i] << " "}cout << endl; 
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " "}cout << endl;} 


void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
bool cmp(pii x, pii y){
    if(x.first == y.first){
        return x.second > y.second;
    }
    return x.first < y.first;
}

void update(vi &lis, vi &tree, int s, int e, int tidx, int i, ll v){
    if (s == e){
        lis[i] = v;
        tree[tidx] = v; 
        return;
    }
    ll m = mid(s, e);
    if(i > m){
        update(lis, tree, m+1, e, 2*tidx+1, i, v);
    }
    else{ update(lis, tree, s, m, 2*tidx, i, v);}
    tree[tidx] = max(tree[2*tidx], tree[2*tidx+1]);
}

ll query(vi &tree, int s, int e, int tidx, ll l, ll r){
    if (r < s or l > e) return 0;
    if( s >= l and e <= r) return tree[tidx];
    ll m = mid(s, e);
    ll left = query(tree, s, m, 2*tidx, l, r);
    ll right = query(tree, m+1, e, 2*tidx+1, l, r);
    return max(left, right);
}

int main(){
    file_i_o();
    ll n;
    cin >> n;

    vector< pii > arr(n);
    loop(i, 0, n-1){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(all(arr), cmp);

    vi tree(4*n, 0); //build a segment tree
    vi lis(n, 0);
    loop(i ,0, n-1){
        ll element = arr[i].first;
        int index = arr[i].second;
        ll res = query(tree, 0, n-1, 1, 0, index-1);
        update(lis, tree, 0, n-1, 1, index, res+1);
    }
    /* ll max_el = -inf; */
    /* loop(i, 0, n-1){ */
    /*     max_el = max( max_el, lis[i]); */
    /* } */
    cout << *max_element(all(lis));

}
/* INPUT */
/* 8 */
/* 7 3 5 3 6 2 9 8 */
/* OUTPUT */
/* 4 */


