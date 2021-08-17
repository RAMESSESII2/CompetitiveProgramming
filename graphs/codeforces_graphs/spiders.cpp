#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)   r.begin(), r.end()
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("cerr.txt", "w", stderr);
// #endif
}

const int inf = INT_MAX;
int n;
vector<vector<int>> adj;
vector<int> visited;
int dist;
int ans;

 void dfs(int v, int d){
    if(visited[v] == 1) return;
    visited[v] = 1;
    dist = max(d, dist);
    for( auto x: adj[v] ){
        dfs(x, d+1);
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        int u, v;
        adj.assign(n+1, vector<int>());
        for(int i = 1; i <= n-1; i++){
            cin >> u>> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cur = -inf;
        for( int i = 1; i <= n; i++ ){
            visited.assign(n+1, 0);
            dist = -1;
            dfs(i, 0);
            cur = max(cur, dist);
            // cerr << cur << endl;
        }
        ans += cur;
    }
    cout << ans << endl;
    return 0;
}


