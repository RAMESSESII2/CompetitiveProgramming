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
  
void radix_sort(vector<pair<pair<int, int>, int>> &a){
     ll n = int(a.size());
    //count sort on the a.first.second
     {
         vector<pair<pair<int, int>, int>> new_arr(n);
         vi bucket(n, 0);
         for(auto x: a){
             bucket[x.first.second]++;
         }
         vi pos(n);
         pos[0] = 0;
         for(int i=1; i<n; i++){
             pos[i] = pos[i-1] + bucket[i-1];
         }
         for(int i=0; i<n; i++){
             int j = a[i].first.second;
             new_arr[pos[j]] = a[i];
             pos[j]++;
         }
         a = new_arr;
     }
    //count sort on the a.first.first   
     {
         vector<pair<pair<int, int>, int>> new_arr(n);
         vi bucket(n, 0);
         for(auto x: a){
             bucket[x.first.first]++;
         }
         vi pos(n);
         pos[0] = 0;
         for(int i=1; i<n; i++){
             pos[i] = pos[i-1] + bucket[i-1];
         }
         for(int i=0; i<n; i++){
             int j = a[i].first.first;
             new_arr[pos[j]] = a[i];
             pos[j]++;
         }
         a = new_arr;
     }
}

void run_case(){
    string s;
    cin >> s;
    s += "$";
    ll n = s.size();
    vi p(n);
    vi c(n);
    {
        vector<pair<char, int>> ch_int(n);
        int i = 0;
        for(auto &x: ch_int){
            x = make_pair(s[i], i);
            i++;
        }
        sort(all(ch_int));
        for(int i = 0; i < n; i++){
            p[i] = ch_int[i].second;
        } 
        c[p[0]] = 0;
        for(int i=1; i<n; i++){
            if(ch_int[i].ff == ch_int[i-1].ff){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }
    ll k = 0;
    while( 1<<k < n){
        vector<pair<pair<int, int>, int>> a(n);
        for(int i = 0; i<n; i++){
            a[i] = {{c[i], c[(i+ (1<<k))%n]}, i};
        }
        radix_sort(a);
        for(int i = 0; i < n; i++){
            p[i] = a[i].second;
        } 
        c[p[0]] = 0;
        for(int i=1; i<n; i++){
            if(a[i].ff == a[i-1].ff){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    // longest common prefix between two consecutive suffixes in lexicographic order
    k = 0;
    vi lcp(n);
    for(int i = 0; i<n-1; i++){
        int pi = c[i];
        int x = p[pi-1];
        while(s[i+k] == s[x+k]) k++;
        lcp[pi] = k;
        k = max(0ll, k-1);
    }
    int j = 1;
    loop(i, 0, n){
        cout << "Substrig starting at" << " " << i << " " << s.substr(p[i], n-p[i]) << endl;
        if(i!=n-1){
        cout << lcp[j++] << endl;
        }
    }
    // number of different substrings
    // remember each substring is a prefix of some suffix
    // $
    // 0
    // a so only 1 prefix possible here
    // 1
    // a b a b b a so (5-1) possible here
    // 2
    // a b b a so (4-2) possible substrings here
    // 0
    // b a
    // 2
    // b a b b a
    // 1
    // b b a
    ll count = 0;
    for(int i = 1; i < n; i++){
        count += (n-p[i]-1 - lcp[i]);
    }
    cout << count << endl;
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

