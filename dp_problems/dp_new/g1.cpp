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
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}
int n;
vector< vector<pair<int, int> >> adj;

int dfs(int root, int p){
    int ans = 0;
    for( auto [x, y]: adj[root] ){
        if( x == p ) continue;
        ans = max(ans, dfs(x, root)+y);
    }
    return ans;
}
//O(V+E)

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        adj.resize(n+1, vector<pair<int, int> >());
        int u, v, w;
        while( cin >>  u){
            cin >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        cout << dfs(1, 0) << endl;
    }
    return 0;
}

