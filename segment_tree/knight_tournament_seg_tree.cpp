
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
            
void query(vi &tree, vi &defarr, ll s, ll e, ll tidx, ll l, ll r, ll val){
    if( s>r or e<l){
        return;
    }
    if(tree[tidx] == 1){
        return;
    }
    if ( s==e ){ 
        if(tree[tidx]==-1 and s != val){
        tree[tidx] = 1;
        defarr[s] = val;
        }
        return;
    }
    ll m = mid(s, e);
    query(tree, defarr, s , m, 2*tidx, l ,r, val);
    query(tree, defarr, m+1 , e, 2*tidx+1, l ,r, val);
    tree[tidx] = (tree[2*tidx]==1 && tree[2*tidx+1]==1) ? 1 : -1;
}

int main(){
    clock_t begin = clock();
    file_i_o();
    ll n=0, m=0;
    cin >> n >> m; 
    vi defarr(n, -1);
    vi tree(4*n, -1);
    loop(i, 0, m-1){
        ll l, r, val;
        cin >> l >> r >> val;
        query(tree, defarr, 0, n-1, 1, l-1, r-1, val-1);
    }
    loop(i, 0, n-1){
        cout << defarr[i]+1 << " ";
    }
    
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


