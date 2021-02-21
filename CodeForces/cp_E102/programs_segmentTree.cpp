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
            
bool compare(int a, int b){
    return a>b;
}

struct node{
    int sum, min, max;
};

node operator+(node a, node b){
    return {
            a.sum + b.sum,
            min(a.min, a.sum + b.min),
            max(a.max, a.sum + b.max)
    };
};
vector<node> pref(20000), suff(20000);
vector<node> tree(200000);
string s;
ll n, m;
ll l, r;

void build(vector<node> &tree, string arr, ll s, ll e, ll tidx){
    if(s == e){
        if(arr.substr(s, 1) == "-"){
            tree[tidx].sum = -1;
            tree[tidx].min = -1;
            tree[tidx].max = 0;
        }
        else{ 
            tree[tidx].sum = 1;
            tree[tidx].min = 0;
            tree[tidx].max = 1;
        }
        return;
    }
    ll m = mid(s, e);
    ll left = 2*tidx;
    ll right = left +1;
    build(tree, arr, s, m, left);
    build(tree, arr, m+1, e, right);
    tree[tidx] = tree[left] + tree[right];
}

node query(vector<node> &tree, ll s, ll e, ll tidx, ll l, ll r){
    if( s>r or e<l){
        node c;
        c.sum = 0;
        c.min = 0;
        c.max = 0;
        return c;
    }
    if(s>=l and e<=r){
        return tree[tidx];
    }
    ll m = mid(s, e);
    node left = query(tree, s , m, 2*tidx, l ,r);
    node right = query(tree, m+1 , e, 2*tidx+1, l ,r);
    return left + right;
}


int main(){
    clock_t begin = clock();
    file_i_o();
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> m;
        cin >> s;
        //using segment tree
        tree.resize(4*n);
        build(tree, s, 0, n-1, 1);// segment tree giving TLE but answeres are correct
        //using prefix suffix
        /* pref.resize(n); */
        /* suff.resize(n); */
        /* for(int i = 0; i < n; ++i){ */
        /*     int x = s[i] == '-' ? -1 : 1; */
        /*     pref[i+1] = pref[i] + node({x, x, x}); */
        /* } */
        /* for(int i = n-1; i >= n; --i){ */
        /*     int x = s[i] == '-' ? -1 : 1; */
        /*     suff[i] = node({x, x, x}) + suff[i+1]; */ 
        /* } */
        while(m--){
            cin >> l >>r;
            node left{0, 0, 0}, right{0, 0, 0}, qns{0, 0, 0};
            if(l > 1)left =query(tree, 0, n-1, 1, 0, l-2);
            if(r < n) right =query(tree, 0, n-1, 1, r, n-1);
            // for prefix suffix- not correct though
            /* l--; */
            /* left = pref[l-1]; */
            /* right = suff[r]; */
            qns = left + right;
            cout << qns.max - qns.min + 1 << endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


