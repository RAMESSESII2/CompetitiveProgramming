/* You are given a sequence A[1], A[2], ..., A[N] ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows: */

/* Update: */

/* This will be indicated in the input by a 'U' followed by space and then two integers i and x. */

/* U i x, 1 ≤ i ≤ N, and x, 0 ≤ x ≤ 10^8. */

/* This operation sets the value of A[i] to x. */
/* Query: */

/* This will be indicated in the input by a 'Q' followed by a single space and then two integers i and j. */

/* Q x y, 1 ≤ x < y ≤ N. */

/* You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j]. */ 
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
#define loop(i, a, b)   for(int i=(a); i<=b; i++)
#define loopr(i, a, b)  for(int i=(a); i>=b; i--)

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
            

void build(vi &arr, vector<pii> &tree, ll s, ll e, ll tidx){
    if(s==e){
        tree[tidx].first = arr[s];
        tree[tidx].second = INT_MIN;
        return;
    }

    int m = mid(s, e);
    build(arr, tree, s, m, 2*tidx);
    build(arr, tree, m+1, e, 2*tidx+1);

    tree[tidx].ff =max(tree[2*tidx+1].ff, tree[2*tidx].ff);

    tree[tidx].ss = min(max(tree[2*tidx+1].ss, tree[2*tidx].ff), max(tree[2*tidx].ss, tree[2*tidx+1].ff));
}

pii query(vector<pii> &tree, ll s, ll e, ll tidx, ll l , ll r){
    pii res;
    res.ff = res.ss = INT_MIN;
    if(s>r || e<l){
        return res;
    }
    if(s>=l && e<=r){ return tree[tidx];}
    ll m = mid(s, e);
    pii left = query(tree, s, m, 2*tidx, l, r);
    pii right = query(tree, m+1, e, 2*tidx+1, l, r);
    res.ff = max(left.ff, right.ff);
    res.ss = min(max(left.ss, right.ff), max(right.ss, left.ff));
    return res;
}

void update(vector<pii> &tree, vi &arr, ll s, ll e, ll tidx, ll index, ll val){
    if(s==e){
        arr[s] = val;
        tree[tidx].ff = val;
        tree[tidx].ss = INT_MIN;
        return;
    }
    ll m = mid(s, e);
    if( m >= index){
    update(tree, arr, s, m, 2*tidx, index, val);
    }
    else{
    update(tree, arr, m+1, e, 2*tidx+1, index, val);
    }

    tree[tidx].ff =max(tree[2*tidx+1].ff, tree[2*tidx].ff);

    tree[tidx].ss = min(max(tree[2*tidx+1].ss, tree[2*tidx].ff), max(tree[2*tidx].ss, tree[2*tidx+1].ff));
}

int main(){
    clock_t begin = clock();
    file_i_o();
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n-1){
        cin >> arr[i];
    }
    ll q;
    cin >> q;
    vector<pii> tree(4*n);
    build(arr, tree, 0, n-1, 1);
    loop(i, 0, q-1){
        ll x, y;
        string c;
        cin >> c >> x >> y; 
        if (c=="Q"){
            pii res;
            res = query(tree, 0, n-1, 1, x-1, y-1);
            cout << res.ff+res.ss << endl;
        }
        else{
            update(tree, arr, 0, n-1, 1, x-1, y);
        }
    }

    /* pii res; */
    /* res = query(tree, 0, 4, 1, 0, 3); */
    /* cout << res.ff+res.ss << endl; */
    /* pii res1; */
    /* res1 = query(tree, 0, 4, 1, 1, 4); */
    /* cout << res1.ff+res1.ss << endl; */
    /* update(tree, arr, 0, 4, 1, 0, 6); */
    /* res1 = query(tree, 0, 4, 1, 0, 4); */
    /* cout << res1.ff+res1.ss << endl; */
    
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}
/* Input */
/* 5 */
/* 1 2 3 4 5 */
/* 6 */
/* Q 2 4 */
/* Q 2 5 */
/* U 1 6 */
/* Q 1 5 */
/* U 1 7 */
/* Q 1 5 */

/* OUtput */

/* 7 */
/* 9 */
/* 11 */
/* 12 */


/* Executed In: 0.000119 seconds */
