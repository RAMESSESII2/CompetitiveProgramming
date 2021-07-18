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
vector<vi> adj;
vi leaf;

void dfs(int v, int p){
    int deg = 0;
    for( auto x: adj[v]){
        if( x != p){
            dfs(x, v);
            deg++;
        }
    }
    if(deg==0) leaf.push_back(v);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        int u, v;
        adj.assign(n+1, vector<int>());
        leaf.clear();
        for( int i = 1; i < n; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        int root = 1;
        for( int i = 1; i <= n; i++){
            if( (int)adj[i].size() >= 3){ 
                count++;
                root = i;
            }
        }
        if( count >= 2 ){
            cout << "No\n";
        }
        else{
            dfs(root, -1);
            cout << "Yes\n";
            int s = (int)leaf.size();
            cout << s << endl;
            for( int i = 0; i < s ; i++ ){
                cout << root << " " << leaf[i] <<endl;
            }
        }
    }
    return 0;
}


