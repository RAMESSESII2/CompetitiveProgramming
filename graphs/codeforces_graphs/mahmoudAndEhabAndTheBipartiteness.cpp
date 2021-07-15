#include<bits/stdc++.h>
#include <numeric>
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
vector<vector<int> > adj;
vector<int> color;

void dfs(int v, int p, int c){
    color[v] = c;
    for( auto x: adj[v] ){
        if( x == p ) continue;
        dfs(x, v, c^1);
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        int v, u;
        cin >> n;
        adj.clear();
        adj.resize(n+1);
        color.resize(n+1);
        for( int i = 1; i < n; i++ ){
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        dfs(1, -1, 0);
        // for( auto x: color ) cerr << x <<" ";
        ll t = accumulate(color.begin(), color.end(), 0l);
        ll ans = 1LL*t*(n-t);
        cout << ans-(n-1) << endl;
    }
    return 0;
}


