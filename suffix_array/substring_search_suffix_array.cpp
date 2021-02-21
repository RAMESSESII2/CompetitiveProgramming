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

/* bool sortbysec(const pair<int,int> &a, */ 
/*               const pair<int,int> &b) */ 
/* { */ 
/*     return (a.second < b.second); */ 
/* } */ 

int binary_Search(string s,const vector<int> &p,string ssearch){
    ll low = 0;
    ll high = sz(s)-1;
    ll len = sz(ssearch);
    while(low <= high){
        ll m = mid(low, high);
        string  c = s.substr(p[m], len%sz(s));
        if (ssearch == c){
            return 1;
        }
        else{
            loop(i, 0, len){
                if(ssearch[i] == c[i]){
                    continue;
                }
                else if (ssearch[i] > c[i%sz(ssearch)]){
                    low = m+1;
                    break;
                }
                else {
                    high = m-1;
                    break;
                }
            }
        }
    }
    return -1;
}

void radix_sort(vector<pair<pair<int, int>, int >> &a){
    int n = sz(a);
    {
        vector<pair<pair< int, int> , int>> a_new(n);
        vi bucket(n, 0);
        for(auto x: a){
            bucket[x.ff.ss]++;
        }
        vi pos(n);
        pos[0] = 0;
        loop(i, 1, n){
            pos[i] = pos[i-1] + bucket[i-1];
        }
        for(auto x: a){
            int i = x.ff.ss;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
    {
        vector<pair<pair< int, int> , int>> a_new(n);
        vi bucket(n, 0);
        for(auto x: a){
            bucket[x.ff.ff]++;
        }
        vi pos(n);
        pos[0] = 0;
        loop(i, 1, n){
            pos[i] = pos[i-1] + bucket[i-1];
        }
        for(auto x: a){
            int i = x.ff.ff;
            a_new[pos[i]] = x;
            pos[i]++;
        }
        a = a_new;
    }
}

void run_case(){
    string s;
    cin >> s;
    s += "$";
    ll n = sz(s);
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> chint(n);
        int i = 0;
        for(auto &x : chint){
            x = {s[i], i};
            i++;
        }
        sort(all(chint));
        loop(i, 0, n){
            p[i] = chint[i].ss;
        }
        c[0] = 0;
        loop(i, 1, n){
            if(chint[i].ff == chint[i-1].ff){
                c[p[i]] = c[p[i-1]];
            }
            else c[p[i]] = c[p[i-1]]+1;
        }
    }
    {
        int k = 0;
        while((1<<k) < n){
            vector<pair<pair<int, int>, int> > a(n);
            loop(i, 0, n){
                a[i] = {{c[i], c[(i+(1<<k))%n]}, i};
            }
            radix_sort(a);
            /* sort(all(a)); */
            loop(i, 0, n){
                p[i] = a[i].ss;
            }
            c[0] = 0;
            loop(i, 1, n){
                if(a[i].ff == a[i-1].ff){
                    c[p[i]] = c[p[i-1]];
                }
                else c[p[i]] = c[p[i-1]]+1;
            }
            k++;
        }
    }
    /* loop(i, 0, n){ */
    /*     cout << s.substr(p[i], n-p[i]) << endl; */
    /* } */
    ll z;
    cin >> z;
    while(z--){
        string sstr;
        cin >> sstr;
        int res = binary_Search(s, p, sstr);
        if (res == -1){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
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


