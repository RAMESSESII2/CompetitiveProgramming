//===============Template==================
#include <bits/stdc++.h>
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

const int MAX = 200007;
int tests;
int n;
int u, v;
vi adj[MAX];
int dp[MAX][2];
vi arr;
//dfs for dp approach
void dfs(int v, int p){
    for( int x: adj[v] ){
        if( x != p ){
            dfs(x, v);
            dp[v][0] += max(dp[x][0], dp[x][1]);
        }
    }
    for( int x: adj[v] ){
        if( x != p ){
            dfs(x, v);
            dp[v][1] = max(dp[v][1], dp[x][0] + 1 + dp[v][0] - max(dp[x][0], dp[x][1]));
        }
    }

}

//dfs for greedy approach
bool done[MAX];
int ans = 0;
void dfs2(int pre, int cur){
    for( int i : adj[cur] ){
        if( i != pre){
            dfs(cur, i);
            if( !done[i] && !done[cur] ){
                done[i] = done[cur] = 1, ans++;
            }
        }
    }
}
            
int main(){
    file_i_o();
    cin >> n;
    for( int i = 0; i < n-1;  i++ ){
        cin >> u >> v;
        //uncomment for the dp approach
        // u--; v--;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    // dp approach
    // dfs(0, -1);
    // cout << max(dp[0][0], dp[0][1]) << '\n';

    // greedy approach
    dfs2(0, 1);
    cout << ans << '\n';
    return 0;
}

