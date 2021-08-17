#include<bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
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
int n;
int m1, m2;
struct DisjointSet{
    vi parent;
    vi rk;
    DisjointSet(int n){
        parent.resize(n+1);
        rk.resize(n+1, 0);
        for( int i = 1; i <= n; i++ ){
            parent[i] = i;
        }
    }
    int getParent(int u){
        return (parent[u]==u)? u: parent[u] = getParent(parent[u]);
    }
    bool merge(int a, int b){
        int u = getParent(a);
        int v = getParent(b);
        if( u == v ) return false;
        if( rk[u] == rk[v]) rk[u]++;
        if( rk[u] > rk[v] ){
            parent[v] = u;
        }
        else parent[u] = v;
        return true;
    }
};

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n >> m1 >> m2;
        DisjointSet dj1(n);
        DisjointSet dj2(n);
        int u, v;
        for(int i = 0; i < m1; i++){
            cin >> u >> v;
            dj1.merge(u, v);
        }
        for(int i = 0; i < m2; i++){
            cin >> u >> v;
            dj2.merge(u, v);
        }
        int ans = 0;
        vector<pair<int, int> > edges;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if( i == j ) continue;
                if( (dj1.getParent(i) != dj1.getParent(j) &&(dj2.getParent(i) != dj2.getParent(j)) )){
                    dj1.merge(i, j);
                    dj2.merge(i, j);
                    ans++;
                    edges.push_back({i, j});
                }
            }
        }
        cout << ans <<endl;
        for( auto [x, y]: edges ){
            cout << x << " " << y << endl;
        }
    }
    return 0;
}


