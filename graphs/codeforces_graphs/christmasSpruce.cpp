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
vector<vector<int> > adj;

bool dfs(int v){
    if( adj[v].empty() ) return 1;
    int count = 0;
    for( auto x: adj[v] ){
        if(adj[x].empty()){
            count++;
        }
    }
    return count >= 3;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        adj.clear();
        adj.resize(n+1);
        for( int i = 2; i < n+1; i++ ) {
            int u;
            cin >> u;
            adj[u].push_back(i);
        }
        // for( int i = 1; i < n+1; i++ ) {
        //     for(auto x: adj[i]) cerr << x << " ";
        //     cerr << endl;
        // }
        bool ans = true;
        for( int i = 1; i < n+1; i++){
            if( !dfs(i) ){
                // cerr << i << endl;
                ans = false;
                break;
            }
        }
        if( ans ) cout << "Yes";
        else cout <<"No";
        cout << endl;
    }
    return 0;
}


