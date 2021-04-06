//===============Template==================
#include <algorithm>
#include <bits/stdc++.h>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;

#define endl            '\n' 
#define ll              long long int
#define ld              long double
#define pb              push_back
#define ff              first
#define ss              second
#define infl             1e18
#define inf              1e9
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

#define print(dp, n); \
    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 

#define countsetbits(i)\
    __builtin_popcount(i)
typedef pair< ll,ll > pll;
typedef pair< int, int> pii;
typedef pair< double, double> pdd;

typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< string > vs;
typedef vector< double > vd;

typedef vector< vi > vvi;
typedef vector< vl > vvl;
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}
const int MAX = 100001;
int n, m, k, p, q;
vi adj[MAX];
int dp[MAX];

int longestPath(int src){
    if( dp[src] != -1 ) return dp[src];
    int res = -inf;
    bool no_nb = true;
    for( auto nb: adj[src] ){
        no_nb = false;
        res = max(longestPath(nb), res);
    }
    return dp[src] = no_nb? 0 : res+1;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();

    // int tests;
    // cin >> tests;
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    loop(i, 0, m){
        cin >> p >> q;
        adj[p].pb(q);
    }
    int ans = 0;
    loop(i, 0, n){
        ans = max(ans, longestPath(i+1));
    }
    cout << ans << '\n';
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

//Debug
//1. size of vi and other containers if applicable
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

