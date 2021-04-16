//===============Template==================
#include <algorithm>
#include <bits/c++config.h>
#include <bits/stdc++.h>
#include <ios>
#include <vector>
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
const string YES = "YES";
const string NO = "NO";

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

const int modd = 1000000009;
const int MAX = 1000007;
int tests;
int n, m;
int x, y, d;
vl energy;
vector<vector<pair<int, ll> > > adj;
vl cb;
vl dist;
vl leaf;
vl visited;

void  dfs(int v ){
    if( visited[v] ) return;
    visited[v] = true;
    for( auto [x, y]: adj[v] ){
        if( visited[x] )continue;
        cb[x] = cb[v]+1;
        dist[x] = dist[v] + y*cb[v];
        // if( adj[x].empty() ) leaf.pb(dist[x]);
        dfs(x);
    }
}

void run_case(){
    cin >> n >> m;
    energy.resize(m+1);
    loop(i, 1, m+1) cin >> energy[i];
    adj.resize(n+1);
    visited.resize(n+1, false);
    cb.resize(n+1);
    dist.resize(n+1);
    cb[1] = 1;
    dist[1] = 0;
    loop(i, 1, n){
        cin >> x >> y >> d;
        // edge[i] = {{x, y}, d};
        adj[x].pb({y, d});
        adj[y].pb({x, d});
    }
    if( n == 1  ) {
        cout << 0 << endl;
        return;
    }
    dfs(1);
    loop(i, 2, n+1){
        if( sz(adj[i]) == 1 ) leaf.pb(dist[i]);
    }
    sort(all(leaf));
    sort(all(energy));
    print(leaf, sz(leaf));
    cerr << endl;
    loop(i, 0, sz(energy))cerr << energy[i] << " ";
    cerr << endl;
    ll ans = 0;
    int i = 1, j = 0;
    while( i<= m && j < sz(leaf) ){
        if( energy[i] >= leaf[j]){
            i++; j++; ans++;
        }
        else i++;
    }
    cout << ans << endl;
    energy.clear();
    adj.clear();
    dist.clear();
    cb.clear();
    leaf.clear();
    visited.clear();
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    // int tests = 1;
    cin >> tests;

    for( int i = 1; i <= tests; i++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}
