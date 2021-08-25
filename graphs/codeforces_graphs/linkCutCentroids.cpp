#include <algorithm>
#include<bits/stdc++.h>
#include <iterator>
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
const int maxm = (int)1e5+9;
int n;
vector<vector<int>> adj;
int leaf, other;
int centroid;

int dfs(int z, int p){
    bool this_is_a_centroid = 1;
    int graph_size = n-1;
    int s = 1;
    for( int x: adj[z] ){
        if( x == p || x == leaf ) continue;
        int temp = dfs(x, z);
        s += temp;
        if( temp > graph_size/2 ){
            this_is_a_centroid = 0;
        }
    }
    if( p != 0) {
        int temp = graph_size-s;
        if( temp > graph_size/2){
            this_is_a_centroid = 0;
        }
    }
    if( this_is_a_centroid){
        centroid = z;
    }
    return s;
}

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        int u, v;
        adj.assign(n+1, vector<int>());
        for( int i = 0; i < n-1; i++ ){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        centroid = 0;
        for(int i = 1; i <= n; i++){
            if( (int)adj[i].size() == 1){
                leaf = i;
            }
            else other = i;
        }
        dfs(other, 0);
        cout << leaf << " " << adj[leaf][0] << endl;
        cout << centroid << " " << leaf << endl;
    }
    return 0;
}


