//===============Template==================
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define endl            '\n' 
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
#define print(dp, n); \
    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 
#define printPair(pr, n); \
    loop(i, 0, n){cerr << pr[i].ff << " " << pr[i].ss << " ";}cerr << endl; 
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
const string YES = "YES\n";
const string NO = "NO\n";

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
//=================Template Ends=====================

const int modd = 1000000007;
const int MAX = 100007;
int tests;
int n, m, k;
int u, v;
vi adj[MAX];
ll dp[MAX][4];
int colored[MAX];

void dfs(int v, int p){
    ll o = 1, t = 1, th = 1;
    for( int x : adj[v] ){
        if( x != p ){
            dfs(x, v);
            th *= (dp[x][1]+dp[x][2])%modd;
            t *= (dp[x][1]+dp[x][3])%modd;
            o *= (dp[x][3]+dp[x][2])%modd;
            th %= modd;
            t %= modd;
            o %= modd;
        }
    }
    if( colored[v] == 1 ) t = th = 0;
    if( colored[v] == 2 ) o = th = 0;
    if( colored[v] == 3 ) o = t = 0;
    dp[v][1] = o;
    dp[v][2] = t;
    dp[v][3] = th;
}

int main(){
    // file_i_o();
    ifstream cin( "barnpainting.in" );
    ifstream cout( "barnpainting.out" );
    cin >> n >> k;
    loop(i, 0, n-1){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i, 0, k){
        cin >> u >> m;
        colored[u] = m;
    }
    dfs(1, -1);
    // loop(i, 1, n+1){
    //     loop(j, 0, 4) cerr<< dp[i][j] << " ";
    //     cerr << endl;
    // }
    cout << (dp[1][1] + dp[1][2] + dp[1][3])%modd << endl;

    return 0;
}
//Debug
//1. size of vi and other containers if applicable
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

