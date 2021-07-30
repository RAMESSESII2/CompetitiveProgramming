#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

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
//if the graph has a total of k colors used then 
// one has to check for each 1 <= color <= k, if there exists a path which can be reached totally by following those colord edges.

int n, m;
vector<vector<pii>> adj;
set<int> colors;
int dp[105][105][105];
int visited[105];

int dfs(int u,int p,  int v, int c){
    if( visited[u] == 1 ) return 0;
    if( u == v ) return 1;
    visited[u] = 1;
    int ans = 0;
    for(auto x: adj[u]){
        if( x.first == p || x.second != c ) continue;
        ans |= dfs(x.first, u, v, c);
    }
    return ans;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n >> m;
        adj.assign(n+1, vector<pii>());
        int u, v, c;
        // memset(dp, -1, sizeof dp);
        for( int i= 0; i < m; i++ ){
            cin >> u >> v >> c;
            colors.insert(c);
            dp[u][v][c] = 1;
            dp[v][u][c] = 1;
            adj[v].push_back({u, c});
            adj[u].push_back({v, c});
        }
        int q;
        cin >> q;
        for( int i= 0; i < q; i++){
            cin >> u >> v;
            int ans = 0;
            for( auto x: colors){
                memset(visited, 0, sizeof visited);
                ans += dfs(u, -1, v, x);
            }
            cout << ans << endl;
        }
    }
    return 0;
}


