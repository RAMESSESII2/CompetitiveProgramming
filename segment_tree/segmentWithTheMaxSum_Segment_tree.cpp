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
#include <random>
#include <cassert>
#include <chrono>
#include <cmath>
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
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */

/* class Node{ */
/*     public: */
/*         ll sum; */
/*         ll maxsum; */
/*         ll ss; */
/*         ll ps; */
/* }; */

struct Node{
    ll sum;
    ll maxsum;
    ll ss;
    ll ps;
};

void build(vi &arr, vector<Node> &tree, ll s, ll e, ll tidx){
    if(s == e){
        tree[tidx].maxsum = max(0LL, arr[s]);
        tree[tidx].sum = arr[s];
        tree[tidx].ss = max(0LL, arr[s]);
        tree[tidx].ps = max(0LL, arr[s]);
        return;
    }
    ll l = 2*tidx;
    ll r = 2*tidx+1;
    ll m = mid(s, e);
    build(arr, tree, s, m, l);
    build(arr, tree, m+1, e, r);
    tree[tidx].maxsum = max({0LL, tree[l].maxsum, tree[r].maxsum, tree[l].sum + tree[r].ps,tree[r].sum + tree[l].ss, tree[l].ss + tree[r].ps});
    tree[tidx].sum = tree[l].sum + tree[r].sum;
    tree[tidx].ss = max(tree[r].ss, tree[l].ss + tree[r].sum);
    tree[tidx].ps = max(tree[l].ps, tree[l].sum + tree[r].ps);
}

void update(vector<Node> &tree, ll s, ll e, ll tidx, ll ind, ll val){
     if(s == e){
        tree[tidx].maxsum = max(0LL, val); 
        tree[tidx].sum =  val;
        tree[tidx].ss = max(0LL, val);
        tree[tidx].ps = max(0LL, val);
        return;
    }
    ll l = 2*tidx;
    ll r = 2*tidx+1;
    ll m = mid(s, e);
    if(ind <= m){
        update(tree, s, m, l, ind, val);
    }
    else{
        update(tree, m+1, e, r, ind, val);
    }
    tree[tidx].maxsum = max({0LL, tree[l].maxsum, tree[r].maxsum, tree[l].ss + tree[r].ps});
    tree[tidx].sum = tree[l].sum + tree[r].sum;
    tree[tidx].ss = max(tree[r].ss, tree[l].ss + tree[r].sum);
    tree[tidx].ps = max(tree[l].ps, tree[l].sum + tree[r].ps);
}
/* Node* query(vector<Node*> &tree, ll s, ll e, ll tidx, ll l, ll r){ */
/*     Node* result; */
/*     result->sum = result->maxsum = result->bps = result->bss = INT_MIN; */
/*     if ( s>r or e<l){ */
/*         return result; */
/*     } */
/*     if (s>=l and e<=r){ */
/*         return tree[tidx]; */
/*     } */
/*     ll m = mid(s,e); */
/*     Node* left = query(tree, s, m, 2*tidx, l, r); */
/*     Node* right = query(tree, m+1, e, 2*tidx+1, l, r); */
/*     result->sum = left->sum + right->sum; */ 

/*     result->bss = max(right->bss, right->sum+left->bss); */

/*     result->bps = max(left->bps, left->sum+right->bps); */

/*     result->maxsum = max({left->maxsum, right->maxsum,  left->sum+right->bps, right->sum+left->bss, left->bss+right->bps}); */

/*     return result; */
/* } */

void run_case(){
   ll n, m;
   cin >> n >> m;
   vi arr(n);
   loop(i, 0, n-1){
       cin >> arr[i];
   }
   vector<Node> tree(4*n);
   build(arr, tree, 0, n-1, 1);
   cout << tree[1].maxsum << endl;
   while(m-- > 0){
       ll ind, val;
       cin >> ind >> val;
       update(tree, 0, n-1, 1, ind, val);
       cout << tree[1].maxsum << endl;
   }
}

int main(){
    clock_t begin = clock();
    file_i_o();

    int tests = 1;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


