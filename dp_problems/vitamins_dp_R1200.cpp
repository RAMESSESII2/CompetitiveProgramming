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
    ll n;
    cin >> n;

    ll f[n+1][8];

    loop(i, 0, n+1){
        loop(j, 0, 8){
            f[i][j] = inf;
        }
    }
    f[0][0] = 0;

    loop(i, 1, n+1){
        ll cost;
        string s;
        cin >> cost >> s;
        int string_mask = 0;
        loop(pos, 0, 3){
            char c = 'C'-pos;
            bool have = 0;
            for(char d:s){
                if(c == d){
                    have = 1;
                }
            }
            if(have == 1){
                string_mask += (1 << pos );
            }
        }
        loop(mask, 0, 8){
            f[i][mask] = min(f[i][mask], f[i-1][mask]);
            f[i][mask | string_mask] = min(f[i][mask | string_mask], f[i-1][mask] + cost);
        }
    }
    ll ans = f[n][7];
    if(ans == inf){ans = -1;}
    cout << ans << '\n';
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


