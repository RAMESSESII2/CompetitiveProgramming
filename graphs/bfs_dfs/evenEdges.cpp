//===============Template==================
#include <algorithm>
#include <bits/stdc++.h>
#include <regex>
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

const int MAX = 100007;
int tests;
int n, m;
int u, v;
vi visited;
vpii d;
vi deg;
vi edge;
vi adj[MAX];
ll k;

// void dfs(int v){
//     visited[v] = 1;
//     k++;
//     if(!edge[v]) edge[v] = k;
//     pii cur({0, 0});
//     int ed = 0;
//     for( auto x: adj[v] ){
//         if( !visited[x] ){
//             ed++;
//             edge[x] = k;
//             visited[x] = 1;
//             cur = max(cur, {deg[x],x});
//         }
//     }
//     if( ed & 1 ){
//         edge[cur.ss] = 0;
//         visited[cur.ss] = 0;
//     }
    
// }
            
void run_case(){
    cin >> n >> m;
    // visited.assign(n+1, 0);
    // edge.assign(n+1, 0);
    deg.assign(n+1, 0);
    // d.assign(n+1, {0, 0});
    loop(i, 0, n+1) adj[i].clear();
    loop(i, 0, m){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    if( (!(m&1))){
        cout << 1 << endl;
        loop(i, 1, n+1) cout << 1 << " ";
        cout << endl;
        return;
    }
    // loop(i, 1, n+1){
    //     d[i-1].ff = deg[i];
    //     d[i-1].ss = i;
    // }
    // sort(all(d), greater<int>());
    // k = 0L;
    // for( v = 1; v <= n; v++ ){
    //     if( adj[v].empty() ){
    //         edge[v] = 1;
    //         continue;
    //     }
    //     if( !visited[v] ){
    //         dfs(v);
    //     }
    // }
    // k = *max_element(all(edge));
    // cout << k << endl;
    // loop(i, 1, n+1) cout << edge[i] << " ";
    // cout << endl;
    bool oddDeg = false;
    loop(i, 1, n+1){
        if( deg[i] & 1 ){
            oddDeg = true;
            break;
        } 
    }
    if( oddDeg ){
        cout << 2 << endl;
        bool f = false;
        loop(i, 1, n+1){
            if( deg[i]&1 & !f){ 
                cout << 1 << " ";
                f= true;
            }
            else cout << 2 << " ";
        }
        cout << endl;
    }
    else{
        cout << 3 << endl;
        loop(i, 1, n+1){
            if( i == u ) cout << 1 << " ";
            else if (i == v) cout << 2 <<" ";
            else cout << 3 <<" ";
        }
        cout << endl;
    }

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

