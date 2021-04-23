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

const int modd = 1000000007;
const int MAX = 10007;
const int lg = 15;
int tests;
int n, m, q;
int x, y;
vi adj[MAX];
int up[MAX][lg+1];
int parent[MAX];
int depth[MAX];

void dfs(int v = 0){
    for( auto x: adj[v] ){
        depth[x] = depth[v] + 1;
        up[x][0] = v;
        for( int i = 1; i < lg; i++ ){
            up[x][i] = up[ up[x][i-1] ][i-1];
        }
        dfs(x);
    }
}
            
void run_case(){
    cin >> n;
    // memset(parent, -1, sizeof parent);
    memset(depth, 0, sizeof depth);
    loop(i, 0, n){
        adj[i].clear();
        cin >> m;
        while( m-- ){
            cin >> x;
            adj[i].pb(x);
        }
    }
    dfs();
    cin >> q;
    for( int s = 0; s < q; s++){
        cin >> x >> y;
        // cerr << x << " " << y << endl;
        if( depth[y] > depth[x] ){
            swap(x, y);
        }
        int k = depth[x]-depth[y];
        // bringing them at equal level
        for( int i = lg; i >= 0; i--){
            if( k >= (1<<i) ){
                x = up[x][i];
                k -= (1<<i);
            }
        }
        // if they are already equal
        if( x == y ){ 
            cout << x << endl;
            continue;
        }
        //where they are not equal, we know the ancestor is above this ancestor
        for( int i = lg; i >= 0; i--){
            if( up[x][i] != up[y][i] ){
                x = up[x][i];
                y = up[y][i];
            }
        }
        // just return parent of any of them
        cout << up[x][0] << endl;
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

