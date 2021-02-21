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

ll len(const pii &a){
    assert(a.ss >= a.ff);
    return (a.ss-a.ff);
}

pii getSeg(ll a, ll b){
    return {min(a, b), max(a,b)};
}

pii getOpt(const pii &a, const pii &b){
    return{
        max({a.ff-b.ss, b.ff-a.ss, 0LL}),
        max({b.ss-a.ff, a.ss-b.ff, 0LL})
    };
}

void run_case(){
    pii point[4];
    loop(i, 0, 3){
        cin >> point[i].ff >> point[i].ss;
    }
    ll ans = inf;
    vector<int> id = {0, 1, 2, 3};
    do{
        ll cur = 0;
        auto x1 = getSeg(point[0].ff, point[3].ff);
        auto x2 = getSeg(point[1].ff, point[2].ff);

        cur += len(x1) + len(x2);
        pii xseg = getOpt(x1, x2);

        auto y1 = getSeg(point[0].ss, point[1].ss);
        auto y2 = getSeg(point[2].ss, point[3].ss);

        cur += len(y1) + len(y2);
        pii yseg = getOpt(y1, y2);

        ll is = min(xseg.ss, yseg.ss) - max(xseg.ff, yseg.ff);
        cur += 2*max(0LL, -is);

        ans = min(ans, cur);
    }
    while (next_permutation(id.begin(), id.end()));
    
    cout << ans << endl;
}


int main(){
    clock_t begin = clock();
    file_i_o();

    int tests;
    cin >> tests;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


