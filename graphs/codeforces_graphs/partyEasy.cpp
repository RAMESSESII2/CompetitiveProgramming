#include <algorithm>
#include<bits/stdc++.h>
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
//keep two different disjoint sets
//1 to store the connnected components and consequently to store a common parent 
//2 to store the components which shouldn't be connected or be used in the answer.

const int inf = INT_MAX;
struct disjointSet{
    vi parent, rk;
    vi vertices;
    disjointSet(int n){
        parent.resize(n+1);
        rk.resize(n+1, 0);
        vertices.resize(n+1, 1);
        for( int i = 1; i <= n; i++ ){
            parent[i] = i;
        }
    }
    int findSet(int a){
        return parent[a] = (parent[a] == a)? a : findSet(parent[a]);
    }
    bool merge(int a, int b){
        a = findSet(a);
        b = findSet(b);
        if( a == b ) return 0;
        if( rk[a] == rk[b] ) rk[a]++;
        if( rk[a] > rk[b] ){ 
            parent[b] = a;
            vertices[a] += vertices[b];
        }
        else { 
            parent[a] = b;
            vertices[b] += vertices[a];
        }
        return 1;
    }
};

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n, k, m;
        int u, v;
        cin >> n >> k;
        disjointSet tog(n);
        for( int i = 0; i < k; i++ ){
            cin >> u >> v;
            tog.merge(u, v);
        }
        cin >> m;
        for( int i = 0; i < m; i++ ){
            cin >> u >> v;
            int a = tog.findSet(u);
            int b = tog.findSet(v);
            if( a == b ){
                tog.vertices[a] = 0;
            }
        }
        int ans = 0;
        for( int i = 1; i < n+1; i++ ){
            if( tog.findSet(i) == i){
                ans = max(ans, tog.vertices[i]);
                // cerr << tog.vertices[i] << endl;
            }
        }
        cout << ans << endl;

    }
    return 0;
}


