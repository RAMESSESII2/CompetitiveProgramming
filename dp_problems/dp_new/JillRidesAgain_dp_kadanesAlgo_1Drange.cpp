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
vi routes(1000000);
void run_case(){
    int n;
    cin >> n;
    int t = n;
    while(n-- ){ 
        int r;
        cin >> r;
        routes.resize(r+1);
        vector<pair<int, int> > dp(r+1);
        loop(i, 1, r) cin >> routes[i];
        int x = 0, y = 0;
        loop(i, 1, r){ 
            if(dp[i-1].ff + routes[i] >= 0){
                dp[i].ff = dp[i-1].ff + routes[i];
                dp[i].ss = dp[i-1].ss;
            }
            else{ 
                dp[i] = {0, i};
            }
        }
        int res = 0;
        /* loop(i, 1, r) cout << dp[i].ff << " " << dp[i].ss << endl; */
        loop(i, 1, r){ 
            if(dp[i].ff >= dp[i-1].ff){
                res = dp[i].ff;
                x = dp[i].ss + 1;
                y = i + 1;
            }
        }
        /* cout << x <<  " " << y << endl; */
        if(res == 0) cout << "Route " << t-n << " has no nice parts" << endl;
        else cout << "The nicest part of route " << t-n << " is between stops " << x << " and " << y << endl;
    }
}

int main(){
    file_i_o();

    int tests = 1;

    while(tests-- > 0)
        run_case();

    return 0;
}


