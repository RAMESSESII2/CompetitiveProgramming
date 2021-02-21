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
    string s;
    cin >> s; 
    s += "$";
    int n = (s.size());
    vector<int> p(n), c(n);
    {
        // size = 0
        vector<pair<char, int>> chint(n);
        loop(i, 0, n) chint[i] = {s[i], i};
        sort(chint.begin(), chint.end());

        loop(i, 0, n){ p[i] = chint[i].ss; }
        c[p[0]] = 0;
        loop(i, 1, n){
            if( chint[i].ff == chint[i-1].ff ) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
    }
    int k = 0;
    while( (1<<k) < n){
        vector<pair<pair<int, int>, int>> a(n);
        loop(i, 0, n){
            a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
        }
        sort(a.begin(), a.end());
        loop(i, 0, n){ p[i] = a[i].ss; }
        c[p[0]] = 0;
        loop(i, 1, n){
            if( a[i].ff == a[i-1].ff ) c[p[i]] = c[p[i-1]];
            else c[p[i]] = c[p[i-1]] + 1;
        }
        k++;
    }
    //o(n) algo to find the length of the longest common prefix
    vector<int> lcp(n);
    k = 0;
    for(int i = 0; i<n-1; i++){
        //pi is the position of the suffix i in the suffix array
        int pi = c[i];
        //previous suffix in the suffix array
        int j = p[pi - 1];
        //lcp[i] = lcp(s[i...n-1], s[j..n-1])
        while(s[i+k] == s[j+k]) k++;
        lcp[pi] = k;
        //for the next suffixes, we'll have atleast k-2 common characters in the next suffix.
        k = max(k-1, 0);
    }
    loop(i, 0, n){
        cout << p[i] << " ";
     }
    cout << endl;
    loop(i, 1, n){
        /* cout << lcp[i] << " " << p[i] << " " << s.substr(p[i], n-p[i]) << endl; */
        cout << lcp[i] << " "; 
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


