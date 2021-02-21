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
            
bool compare(int a, int b){
    return a>b;
}

ll solve(ll n, vi &arr, ll x, ll ans){
    vi newarr = arr;
    sort(all(newarr));
    if (newarr== arr){ 
        return 1;
    }
    if( *max_element(all(arr)) < x){ 
        return -1;
    }
    loop(i, 1, n){
        if(arr[i] < arr[i-1]){
            loop(j, 1, i-1){
                ll sum = INT_MAX;
                if(arr[j] > x){
                    vi newarr = arr;
                    sort(all(newarr));
                    swap(arr[j], x);
                    if (newarr == arr){
                        return 1+ans;
                    }
                    ll val = 1 + solve(n, arr, x, ans);
                    if(val != -1) sum = min(sum, val);
                }
                if(sum != INT_MAX) ans += sum;
            }
        }
    }
    return ans;
}

int main(){
    clock_t begin = clock();
    file_i_o();
    ll t;
    cin >> t;
    loop(j, 1, t){
        ll n, x;
        cin >> n >> x;
        vi arr(n);
        loop(i, 0, n-1){
            cin >> arr[i];
        }
        auto get_first = [&] {
            loop(i, 0, n-1){
                if (arr[i] > x)
                    return i;
            }
            return -1;
        };
        int ans=0;
        while(!is_sorted(all(arr))){
            int index = get_first();
            if (index<0)
                break;
            swap(arr[index], x);
            ans++;
        }
        cout << (is_sorted(all(arr)) ? ans : -1) << '\n';

    }
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


