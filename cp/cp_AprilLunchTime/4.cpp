//===============Template==================
#include <bits/stdc++.h>
#include <vector>
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
const int MAX = 200007;
int tests;
int n, k, a;
int x, y, u, v;
map<int, int> sp;
vi adj[MAX];
vector<pii> dist;

void dfs(int v, int p){
    if( sp[v] ){
        dist[v] = {v, 0};
    }
    else{
        dist[v].ff = dist[p].ff;
        dist[v].ss = dist[p].ss + 1;
    }
    for( auto x: adj[v] ){
        if( x == p ) continue;
        dfs(x, v);
        if( dist[v].ss > dist[x].ss+1 ){
            dist[v].ff = dist[x].ff;
            dist[v].ss = dist[x].ss + 1;
        }
    }
}
map<int, int> to;
void dfs2(int a,int p, int dist){
    if(sp[a]){
        to[a] = dist;
    }
    for( auto x: adj[a]){
        if( x == p ) continue;
        dfs2(x, a, dist+1);
    }
}

void run_case(){
    cin >> n >> k >> a;
    sp.clear();
    int st = 1;
    loop(i, 0, k){
        cin >> x;
        sp[x] = 1;
        st = x;
    }
    dist.clear();
    dist.resize(n+1);
    loop(i, 1, n+1)adj[i].clear();
    loop(i, 1, n){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(st, -1);
    // loop(i, 1, n+1){
    //     cerr << i <<"  " << dist[i].ff << " " << dist[i].ss << endl;
    // }
    to.clear();
    dfs2(a, -1, 0);
    // for( auto x: to ){
    //     cerr << x.ff << " " << x.ss << endl;
    // }
    vpii ans(n+1, 0);
    int cur;
    loop(i,1, n+1){
        cur = 0;
        for( auto x: sp){
            if(cur < to[dist[i].ff]- dist[i].ss){

            }
        }
        cout <<to[dist[i].ff]- dist[i].ss << " ";
    }
    cout <<endl;
    loop(i,1, n+1){
        cout << dist[i].ff << " ";
    }
    cout <<endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    cin >> tests;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

