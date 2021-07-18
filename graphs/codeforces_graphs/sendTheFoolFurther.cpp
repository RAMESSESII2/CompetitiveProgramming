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

const int inf = INT_MAX;
int n;
vector<vector<pii>> adj;

int dfs(int v, int p){
    int ans = 0;
    for( auto x: adj[v] ){
        if( x.first == p ) continue;
        ans = max(ans,x.second+ dfs(x.first, v));
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
        cin >> n;
        adj.assign(n, vector<pii>());
        int u, v, c;
        for( int i = 0; i < n-1; i++){
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        int ans = dfs(0, -1);
        cout << ans << endl;
    }
    return 0;
}


