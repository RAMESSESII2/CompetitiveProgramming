/* You are given an array containing n integers. Your task is to determine the longest increasing subsequence in the array, i.e., the longest subsequence where every element is larger than the previous one. */

/* A subsequence is a sequence that can be derived from the array by deleting some elements without changing the order of the remaining elements. */ 

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
#define print(dp, n); \
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl;
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " "}cout << endl;}

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
    ll n;
    cin >> n;
    vi arr(n);
    loop(i, 0, n-1) cin >> arr[i];
    vi dp(n+1, 0);
    /* 6, 3, 2, 4 */
    dp[1] = 1;
    /* print(dp, n); */
    loop(i, 2, n){
        loopr(j, i-1, 1){
            if (arr[j-1] < arr[i-1]) dp[i] = max(dp[i] ,1 + dp[j]);
            else dp[i] = max(int(dp[i]), 1);
            /* cout << i << " "<< j << " " << dp[i] << endl; */
        /* print(dp, n); */
        }
    }
    /* print(dp, n); */
    cout << *max_element(all(dp));
}


