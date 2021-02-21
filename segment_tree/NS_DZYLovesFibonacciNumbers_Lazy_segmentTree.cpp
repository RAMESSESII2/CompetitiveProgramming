/* DZY loves Fibonacci numbers very much. Today DZY gives you an array consisting of n integers: a1, a2, ..., an. Moreover, there are m queries, each query has one of the two types: */

/*     Format of the query "1 l r". In reply to the query, you need to add Fi - l + 1 to each element ai, where l ≤ i ≤ r. */
/*     Format of the query "2 l r". In reply to the query you should output the value of modulo 1000000009 (109 + 9). */ 

/* Help DZY reply to all the queries. */
/* Input */

/* The first line of the input contains two integers n and m (1 ≤ n, m ≤ 300000). The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 109) — initial array a. */

/* Then, m lines follow. A single line describes a single query in the format given in the statement. It is guaranteed that for each query inequality 1 ≤ l ≤ r ≤ n holds. */
/* For each query of the second type, print the value of the sum on a single line. */
/* 4 4 */
/* 1 2 3 4 */
/* 1 1 4 */
/* 2 1 4 */
/* 1 2 4 */
/* 2 1 3 */

/* Output */
/* 17 */
/* 12 */

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
#define mod             1000000009
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
            
bool compare(int a, int b){
    return a>b;
}

vi fibonacci_number(ll n){
    vi arr(n+1);
    arr[1] = 1;
    arr[2] = 1;
    loop(i, 3, n){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr;
}

void build(vi &tree, vi &arr, ll s, ll e, ll tidx){
    if(s==e){
        tree[tidx] = arr[e];
        return;
    }
    ll m;
    m = mid(s, e);
    build(tree, arr, s, m, 2*tidx);
    build(tree, arr, m+1, e, 2*tidx+1);
    tree[tidx] = (tree[2*tidx]%mod + tree[2*tidx+1]%mod)%mod;
}

void push(ll v, vi &tree, vector<vector<ll>> &lazy, ll s, ll e){
    ll m = mid(s, e);
    loop(i, s, m){
        tree[2*v] += lazy[v][i];
        lazy[2*v][i] += lazy[v][i];
        lazy[v][i] = 0;
    }
    loop(k, m+1,e){
        tree[2*v+1] += lazy[v][k];
        lazy[2*v+1][k] +=  lazy[v][k];
        lazy[v][k] = 0;
    }
    print(tree, 2*n);
}

void update(vi &tree, ll s, ll e, ll tidx, ll l, ll r, vi &fibarr , vector<vector<ll>> &lazy){
    if(s>r or e<l){
        return;
    }
    if(s>=l and e<=r){
        loop(i, l ,r){
            ll index = i-l+1;
            tree[tidx] += fibarr[index];
            lazy[tidx][index-1] = fibarr[index];
        }
    }
    else{
        push(tidx, tree, lazy, s, e);
        ll m = mid(s, e);
        if(m >= l) update(tree, s, m, 2*tidx, l, r, fibarr, lazy);
        if(m < r) update(tree, m+1, e, 2*tidx+1, l, r, fibarr, lazy);
    }
}

ll query(vi &tree, ll s, ll e, ll tidx, ll l, ll r, vector<vector<ll>> &lazy){
    if(s>r or e<l){
        return 0;
    }
    if(s>=l and e<=r){
        return tree[tidx];
    }
    push(tidx, tree, lazy, s, e);
    ll m = mid(s, e);
    ll left = 0 , right =0;
    if(m>=l) left = query(tree, s, m, 2*tidx, l, r, lazy);
    if(m<r) right = query(tree, m+1, e, 2*tidx+1, l, r, lazy);
    return left+right;
}

int main(){
    clock_t begin = clock();
    file_i_o();
    ll n, q;
    cin >> n >> q;
    vi arr(n);
    loop(i, 0, n-1){
        cin >> arr[i];
    }

    vi fibarr(n+1);
    fibarr = fibonacci_number(n);

    vector<vector<ll>> lazy(4*n, vector<ll>(n,0));
    vi tree(4*n);
    build(tree, arr, 0, n-1, 1);

    loop(i, 0, q-1){
        ll type, l,r;
        cin >> type >> l >> r;
        if (type == 1){
            cout << "Update" << endl;
            print(tree, 2*n);
            update(tree, 0, n-1, 1, l-1, r-1, fibarr, lazy);
            print(tree, 2*n);
        }
        else{
            cout << "Query" << endl;
            print(tree, 2*n);
            cout << query(tree, 0, n-1, 1, l-1, r-1, lazy) << endl;
            print(tree, 2*n);
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


