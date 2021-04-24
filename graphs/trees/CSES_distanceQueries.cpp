//===============Template==================
#include <bits/stdc++.h>
#include <limits>
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
const int lg = 20;
int tests;
int n, q;
int x, y, a, b, i, j;
vi adj[MAX];
int up[MAX][lg];
int visited[MAX];
int depth[MAX];
// int parent[MAX];

void dfs(int v = 1){
    if( visited[v] ) return;
    visited[v] = 1;
    for( auto x : adj[v]){
        if( visited[x] ) continue;
        depth[x] = depth[v] + 1;
        up[x][0] = v;
        for( i = 1; i < lg; i++){
            up[x][i] = up[ up[x][i-1] ][i-1];
        }
        dfs(x);
    }
}

int get_distance(int a, int b){
    int distance = 0;
    if( depth[b] > depth[a] ) swap(a, b);
    int k = depth[a] - depth[b];
    for( int i = lg-1; i >=0 ; i--){
        if( k >= (1<<i)){
            a = up[a][i];
            k -= (1<<i);
            distance += (1 << i);
        }
    }
    if( a == b){
        return distance;
    }
    for( int i = lg-1; i >=0 ; i--){
        if( up[a][i] != up[b][i]){
            a = up[a][i]; b = up[b][i];
            distance += 2*(1<<i);
        }
    }
    return distance+2;
}
            
void run_case(){
    cin >> n >> q;
    loop(i, 0, n-1){
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset(visited, 0, sizeof visited);
    memset(up, 0, sizeof up);
    memset(depth, 0, sizeof depth);
    dfs();
    while( q-- ){
        cin >> a >> b;
        cout << get_distance(a, b) << endl;
    }
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    tests = 1;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

