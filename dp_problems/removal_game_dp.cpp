/* There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. Both players try to maximize their scores. */

/* What is the maximum possible score for the first player when both players play optimally? */

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

typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< int,int > ii;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define loop(i; a; b)   for(int i=(a); i<=b; i++)
#define loopr(i; a; b)  for(int i=(a); i>=b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())


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


int main(){
    file_i_o();
    int n;
    cin >> n;
    vi arr(n);
    loop(i; 0; n-1) cin >> arr[i];
    vvi dp( n, vector<ll>(n, 0));

    loop(len; 1; n){
        for(int i=0; i+len<=n; i++){
            int j = i+len-1;
            ll x, y, z;
            x = (i+2 <= j)? dp[i+2][j]: 0;
            y = (i+1 <= j-1)? dp[i+1][j-1]: 0;
            z = (i <= j-2)? dp[i][j-2]: 0;

            dp[i][j] = max(arr[i] + min(x,y), arr[j] + min(y, z));
        }
    }
    cout << dp[0][n-1];
}


