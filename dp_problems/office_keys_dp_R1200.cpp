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
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */

void run_case(){
    ll n, k, p;
    cin >> n >> k >> p;
    ll a[n], b[n];
    /* a is people position */ 
    loop(i, 0, n) {cin >> a[i];}
    sort(a, a+n);
    /* b is keys position */ 
    loop(i, 0, k) {cin >> b[i];}
    sort(b, b+k);

    ll dp[k+1][n+1];

    for(ll i=0; i <=k; i++){
        loop(j, 0, n+1){
            dp[i][j] = inf;
        }
    }
    dp[0][0] = 0;
    for(ll i=0; i<k; i++){
        loop(j, 0, n+1){
            /* dont take the person */
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            /* take the person */
            if(j<n){
                dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j]-b[i]) + abs(b[i]-p)));
            }
        }
    }
    cout << dp[k][n] << '\n';

}

int main(){
    clock_t begin = clock();
    file_i_o();

    int tests;
    tests = 1;

    while(tests--)
        run_case();

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


