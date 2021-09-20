#include <algorithm>
#include<bits/stdc++.h>
#include <iostream>
#include <system_error>
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
int n, k, u, v;
vector<vector<int>> adj;
vector<int> vis;
vector<int> color;
vector<int> answer;

void dfs(int u){
    if( vis[u] ) return;
    vis[u] = 1;
    for( auto &x: adj[u] ){
        if( !vis[x] ){
            dfs(x);
            answer[u] = max(answer[u], answer[x]+((u<x)?1:0));
        }
    }
}

bool isCyclic(int v){
    color[v] = 1;
    for( auto x: adj[v] ){
        if( color[x] == 0 ){
            if( isCyclic(x) ) return true;
        }
        else if(color[x] == 1) return true;
    }
    color[v] = 2;
    return false;
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
        adj.assign(n+1, vector<int>());
        vis.assign(n+1, 0);
        answer.assign(n+1, 1);
        for(int i = 1; i <= n; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> u;
                adj[i].push_back(u);
            }
        }
        //finding cycle
        bool toStop = 0;
        color.assign(n+1, 0);
        for ( v = 1; v <= n; v++ ){
            if( color[v] == 0 && isCyclic(v) ){
                toStop = 1;
                break;
            }
        }
        if(toStop){
            cout << -1 << endl;
            continue;
        }
        //if no cycle found
        vis.assign(n+1, 0);
        for(int i = 1; i <= n ; i++){
            if( vis[i] == 0 ){
                dfs(i);
            }
        }
        cout << *max_element(all(answer))<< endl;
    }
    return 0;
}


