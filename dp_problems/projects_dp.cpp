/* There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day. */

/* What is the maximum amount of money you can earn?There are n projects you can attend. For each project, you know its starting and ending days and the amount of money you would get as reward. You can only attend one project during a day. */

/* What is the maximum amount of money you can earn? */
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
    loop(i, 0, n){cout << dp[i] << " "}cout << endl; 
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " "}cout << endl;} 


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

struct Job{
    ll s, f, p;
};
            
bool compare(Job a, Job b){
    return a.f<b.f;
}

ll binarySearch(Job a[], int i){
    ll hi = i-1, low = 0;
    while(hi >= low){
        ll m = mid(low, hi);
        if (a[m].f < a[i].s){
            if(a[m+1].f < a[i].s){ low = m+1;}
            else return m;
        }
        else{
            hi = m-1;
        }
    }
    return -1;
}

int main(){
    file_i_o();
    ll n;
    cin >> n;
    struct Job arr[n];
    loop(i, 0, n-1){
        cin >> arr[i].s >> arr[i].f >> arr[i].p;
    }
    vi dp(n, 0);
    sort(arr, arr+n, compare);
    dp[0] = arr[0].p;
    loop(i, 1, n-1){
        ll incl = arr[i].p;
        ll excl = dp[i-1];
        ll indx = binarySearch(arr, i);
        if (indx != -1){
            incl += dp[indx];
        }
        dp[i] = max(incl, excl);
    }
    cout << dp[n-1];
}

/* INPUT */
/* 4 */
/* 2 4 4 */
/* 3 6 6 */
/* 6 8 2 */
/* 5 7 3 */
/* OUTPUT */
/* 7 */
