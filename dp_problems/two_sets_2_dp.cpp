/* Your task is to count the number of ways numbers 1,2,…,n can be divided into two sets of equal sum. */

/* For example, if n=7, there are four solutions: */

/*     {1,3,4,6} */

/* and {2,5,7} */

/* {1,2,5,6} */
/* and {3,4,7} */

/* {1,2,4,7} */
/* and {3,5,6} */

/* {1,6,7} */
/* and {2,3,4,5} */

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
    int sum = (n*(n+1))/2;
    /* cout << sum << endl; */
    if(!(sum&1)){
        sum = sum/2;
        /* cout << sum << endl; */
        vvi dp(n+1 , vi (sum+1, 0));

        /* if sum is 0 then we have a combination */
        loop(i, 0, n){
            dp[i][0] = 1;
        }
        /* if we dont have an element left but sum is still >0 */
        loop(j, 1, sum){
            dp[0][j] = 0;
        }

        /* loop(i, 0, n){ */
        /*     loop(j, 0, sum){ */
        /*         cout << dp[i][j] << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        /* int j = sum; */
        loop(i, 1, n){
            loop(j, 1, sum){
            if (j >= i){
                dp[i][j] = dp[i][j]%mod + dp[i-1][j]%mod + dp[i-1][j-i]%mod;
            }
            else dp[i][j]= dp[i][j]%mod + dp[i-1][j]%mod;
            }
        }
        /* loop(i, 0, n){ */
        /*     loop(j, 0, sum){ */
        /*         cout << dp[i][j] << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        cout << (dp[n][sum]/2)%mod;
    }
    else cout << 0;

}

