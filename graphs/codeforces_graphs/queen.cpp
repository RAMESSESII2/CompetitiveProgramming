#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  r.begin(), r.end()
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
vector<vi> adj;
vector<int> c;
vector<int> ans;

int dfs(int v){
    bool ret = c[v];
    for( auto x: adj[v] ){
        ret &= dfs(x);
    }
    if( ret ) ans.push_back(v);
    if( c[v] == 1 ) return 1;
    else return 0;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        adj.resize(n+5);
        c.resize(n+1);
        ans.clear();
        int root = -1;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for( int i = 1; i <= n; i++){
            int u, a;
            cin >> u >> a;
            if( u != -1 ) adj[u].push_back(i);
            c[i] = a;
            if( u == -1 ) root = i;
        }
        dfs(root);
        sort(all(ans));
        for( auto x: ans  ) cout << x << endl;
        if( ans.empty() ) cout << -1 << endl;
    }
    return 0;
}


