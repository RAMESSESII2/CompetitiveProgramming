#include <algorithm>
#include<bits/stdc++.h>
#include <cctype>
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
vector< vector<int> > adj;
map<string,int> mp;

int dfs(int  v){
    int ans = 0;
    for( auto x: adj[v] ){
        ans = max(ans, dfs(x));
    }
    return ans+1;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        string u, v, w;
        cin >> n;
        adj.clear();
        adj.resize(n+2);
        mp.clear();
        int j = 1;
        for( int i = 0; i < n ; i++ ){
            cin >> u >> w >> v;
            transform(u.begin(), u.end(), u.begin(), ::tolower);
            transform(v.begin(), v.end(), v.begin(), ::tolower);
            if( mp[v]==0 ) mp[v] = j++;
            if( mp[u]==0 ) mp[u] = j++;
            adj[mp[v]].push_back(mp[u]);
        }
        // for( auto [x, y]: mp ) cerr << x << " " << y << endl;
        // for( int i = 1; i <= n+1; i++ ){
        //     cerr << i << endl;
        //     for( auto x: adj[i] ) cerr << x << " ";
        //     cerr << endl;
        // }
        cout << dfs(mp["polycarp"]) << endl;
    }
    return 0;
}


