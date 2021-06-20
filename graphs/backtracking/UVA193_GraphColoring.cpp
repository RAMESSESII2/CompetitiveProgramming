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
int TC;
vector<vector<int> > adjList;
vector<bool> visited;
vector<bool> color;
int ans;
vi ansVec;
int N, M;

bool judge(int v){
    for( auto x: adjList[v]){
        if( color[x] && color[v]  ){
            return false;
        }
    }
    return true;
}

void dfs(int v){
    if( v > N ){
        int max  = 0;
        for( int j = 1; j <= N; j++ ){
            if( color[j] == 1 ) max++;
        }
        if( max > ans ){ 
            ans = max;
            ansVec.clear();
            for( int j = 1; j <= N; j++ ){
                if( color[j] == 1 ) ansVec.push_back(j);
            }
        }

    }
    if( v <= N ){
        for( int i = 0; i <= 1; i++ ){
            color[v] = i;
            if( judge(v) ){
                dfs(v+1);
            } 
            color[v] = 0;
        }
    }
}

int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int u, v;
        cin >> N >> M;
        adjList.clear();
        adjList.resize(N+1);
        for( int i = 0; i < M; i++ ){
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        ans = 0;
        color.assign(N+1, -1);
        dfs(1);
        cout << ans << endl;
        for( int i = 0; i < (int)ansVec.size(); i++){
            cout << ansVec[i] << ((i == ans-1) ? "\n" : " ");
        }
    }
    return 0;
}


