#include <algorithm>
#include<bits/stdc++.h>
#include <type_traits>
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
vector<vector<int>> adj;
vi init;
vi goal;
vi arr;
int ans;
int level;
int evenLevels;
int oddLevels;

void dfs(int v, int  p, int  level, int  evenLevels, int  oddLevels ){
    if( level&1 ){
        if( oddLevels&1 ) init[v] ^= 1; 
    }
    else{
        if( evenLevels&1 ) init[v] ^= 1; 
    }
    if( goal[v] != init[v] ){
        ans++;
        if( level&1 ) oddLevels++;
        else evenLevels++;
        arr.push_back(v);
    }
    for( auto x: adj[v] ){
        if( x == p ) continue;
        dfs(x, v, level+1, evenLevels, oddLevels);
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
        int u, v;
        cin >> n;
        ans = 0;
        level = 1;
        evenLevels = 0;
        oddLevels = 0;
        adj.assign(n+1, vector<int>());
        arr.clear();
        for( int i = 1; i < n; i++ ){
            cin >> u >> v;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        init.assign(n+1, 0);
        goal.assign(n+1, 0);
        for(int i = 1; i <=n; i++) cin >> init[i];
        for(int i = 1; i <=n; i++) cin >> goal[i];
        dfs(1, -1, 1, 0, 0 );
        cout << ans << endl;
        for( auto x: arr ) cout << x<< endl;
    }
    return 0;
}


