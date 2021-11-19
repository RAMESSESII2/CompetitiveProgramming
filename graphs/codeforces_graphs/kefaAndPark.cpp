#include <bits/c++config.h>
#include<bits/stdc++.h>
#include <climits>
#include <ctime>
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

const int inf = INT_MAX;
const int Max = (int)2e5+9;
int n, m;
vector<int> adj[Max];
int cats[Max];

int dfs(int v, int p, int encountered){
    if( cats[v] ){
        encountered++;
        if(encountered > m ) return 0;
    }
    if(cats[v] == 0) encountered=0;
     if( v!=1 &&  adj[v].size() == 1){
        return 1;
    }
    int ans = 0;
    for(auto x: adj[v]){
        if( x == p) continue;
        ans += dfs(x, v, encountered);
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
        int u, v;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> cats[i+1] ;
        }
        for(int i = 1; i < n; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // for(int i = 0; i < n; i++){
        //     cerr << endl <<i+1 << ": " << endl;
        //     for(auto x: adj[i+1]) cerr << x << " ";
        // }
        cout << dfs(1, -1, 0);
    }
    return 0;
}


