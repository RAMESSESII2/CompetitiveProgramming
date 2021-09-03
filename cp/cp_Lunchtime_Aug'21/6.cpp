#include<bits/stdc++.h>
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

int LCSubStr(string X, string Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0; // To store length of the
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
struct DisjointSet{
    vi ranks;
    vi parent;
    DisjointSet(int n){
        ranks.resize(n+1, 0);
        parent.resize(n+1);
        for( int i = 1; i <= n; i++) parent[i] = i;
    }
    int findSet(int v){
        return parent[v] = ((parent[v] == v)? v: findSet(parent[v]));
    }
    bool unionSet(int u, int v){
        int x = findSet(u);
        int y = findSet(v);
        if( x == y ) return false;
        if( ranks[x] == ranks[y] ) ranks[x]++;
        if( ranks[x] > ranks[y] ){
            parent[y] = x;
        }
        else parent[x] = y;
        return true;
    }
};

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<string> arr(n+1);
        vector<pair<int, pii>> edges;
        edges.clear();
        for( int i = 1; i <= n; i++) cin >> arr[i];
        for( int i = 1; i <= n; i++){
            for( int j = i+1; j <= n; j++){
                int res = LCSubStr(arr[i], arr[j],(int)arr[i].length(), (int)arr[j].length() );

                edges.push_back({res, {i, j}});
            }
        }
        sort(edges.rbegin(), edges.rend());
        DisjointSet dj(n);
        ll ans = 0l;
        for( auto [x, y]: edges){
            if( dj.unionSet(y.first, y.second) == false ){
                continue;
            }
            // cerr << y.first << " " << y.second << " " << x << endl;
            else ans += 1l*(x);
        }
        cout <<ans << endl;
        // cerr << endl;
    }
    return 0;
}


