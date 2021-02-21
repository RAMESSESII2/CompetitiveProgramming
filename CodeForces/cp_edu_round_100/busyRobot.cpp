//Template
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
#define countetbits(i)\
    __builtin_popcount(i)

typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}
//Type Inference refers to automatic deduction of the data type of an expression in a programming language.
//Auto lets you declare a variable with particular type whereas decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the type of passed expression.

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

/* bool sortbysec(const pair<int,int> &a, */ 
/*               const pair<int,int> &b) */ 
/* { */ 
/*     return (a.second < b.second); */ 
/* } */ 
  

void run_case(){
    int n;
    cin >> n;
    vector<ll> t(n+1), x(n);
    loop(i, 0, n) cin >> t[i] >> x[i];
    t[n] = inf;
    
    int ans = 0;
    //curx : pos of robot 
    //nxt : destination of robot
    //curt : current time
    ll curt = 0, nxt = 0, curx = 0;
    for(int i = 0; i < n; i++){
        ll dx = nxt - curx;
        ll dt = t[i] - curt;
        int dir = dx > 0 ? 1 : -1;
        ll steps = min(abs(dx), dt); 
        curt += dt; curx += steps * dir;
        if(curx == nxt){
            // robot not moving; command received
            nxt = x[i];
        }
        // else robot is moving; ignore command i  don't update nxt
        // first check if [curx, nxt] contains x[i]
        if(min(curx, nxt) <= x[i] && x[i] <= max(curx, nxt)){
            if(abs(curx - x[i]) <= t[i+1] - t[i]){
                //now check that [curx, curx + sign * (t[i+1] - t[i] )] contains x[i]
                ++ans; // previous was successful
            }
        }
    }
    cout << ans << endl;
}

int main(){
    clock_t begin = clock();
    file_i_o();
    /* int tests = 1; */
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


