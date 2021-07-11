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
const int mod = (int)1e9+7;
const int z = (int)4e5+7;

vector<int> adj[z];
int arr[z][2];
bool gone[z];

void dfs(int loc){
    gone[loc] = true;
    for( auto x: adj[loc] ) if( !gone[x] ) dfs(x);
}

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
        for( int i = 1; i <= n; i++ ){
            cin >> arr[i][0];
            adj[i] = vector<int>();
            gone[i] = false;
        }
        for( int i = 1; i <= n; i++ ){
            cin >> arr[i][1];
        }
        for( int i = 1; i <= n; i++ ){
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
        }
        ll ans = 1;
        for( int i = 1; i <= n; i++ ){
            if( !gone[i] ){
                ans = ans*(2l)%mod;
                dfs(i);
            }
        }
        cout << ans%mod << endl;
    }
    return 0;
}


