//===============Template==================
#include <bits/stdc++.h>
#include <cstdint>
#include <numeric>
#include <stdexcept>
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

const int modd = 1000000007;
const int MAX = 1007;
const int x = 1007;
int tests;
int n;
ll X;
int u, v;
vi arr;
vi adj[MAX];
ll dp[MAX][MAX];
int visited[MAX];
ll fact[1003], invfact[1003];

ll power(ll a, ll n){
    if( n == 0 ) return 1;
    ll ans = 1;
    ll val = 1;
    while( n ){
        if( n%2){
            ans *= val;
            ans %= modd;
        }
        val *= val;
        val %= modd;
        n /= 2;
    }
    return ans;
}

bool is_leaf(int l){
    if( sz(adj[l]) == 1)  return true;
    return false;
}

void dfs(int v, int p){
    // if( is_leaf(v) && v != 1 ) return;
    if( visited[v] ) return;
    visited[v] = 1;
    for( auto adjacent: adj[v] ){
        if( visited[adjacent] )continue;
        dfs(adjacent, v);
    }
    for( int j = 1; j <= x; j++ ){
        ll md = 1;
        for( auto y: adj[v] ){
            if( y == p ) continue;
            md *= dp[y][j];
            md %= modd;
        }
        dp[v][j] = md%modd;
    }
    for( int i = 2; i <= x; i++){
        dp[v][i] += dp[v][i-1];
        dp[v][i] %= modd;
    }
}
            
void run_case(){
    cin >> n ;
    cin >> X;
    loop(i, 0, n+1) adj[i].clear();
    loop(i, 0, n-1){
        cin >> u >> v; 
        adj[u].pb(v);
        adj[v].pb(u);
    } 
    memset(dp, 0, sizeof dp);
    memset(visited, 0, sizeof visited);
    dfs(1, -1);
    // loop(i, 1, n+1){
    //     loop(j, 1, n+1){
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    if( X <= x ){
        cout << dp[1][X]%modd << endl;
    }
    else{
        ll temp[n+1];
        temp[0] = X;
        for( int i = 1; i <= n; i++){
            temp[i] = (X-i);
            temp[i] %= modd;
        }

        ll pre[n+1];
        ll suff[n+2];

        pre[0] = temp[0];
        for( int i = 1; i <= n; i++){
            pre[i] = pre[i-1]*temp[i];
            pre[i] %= modd;
        }

        suff[n+1] = 1;
        for( int i = n; i >= 1; i--){
            suff[i] = suff[i+1]*temp[i];
            suff[i] %= modd;
        }

        ll answer = 0;
        for( int i = 1; i <= n; i++ ){
            ll vel = suff[i+1];
            vel %= modd;

            vel *= pre[i-1];
            vel %= modd;

            ll tem = invfact[n-i];
            tem %= modd;

            if( (n-i)&1){
                tem *= (modd-invfact[i]);
                tem %= modd;
            }
            else{
                tem *= invfact[i];
                tem %= modd;
            }

            vel *= tem;
            vel %= modd;

            vel *= dp[1][i];
            vel %= modd;

            answer += vel;
            answer %= modd;
        }
        cout << answer << endl;
    }
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    fact[0] = invfact[0] = 1;
    for( int i = 1; i <= 1000; i++){
        fact[i] = i*fact[i-1];
        fact[i] %= modd;
        invfact[i] = power(i, modd-2)*invfact[i-1];
        invfact[i] %= modd;
    }

    cin >> tests;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

