#include<bits/stdc++.h>
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
const int z = (int)2e3+3;
int dp[z][z];

void pre(){
    for( int i = 1; i < z; i++ ) dp[1][i] = 1;
    for( int i = 1; i < z; i++ ){
        for( int j = 1; j < z; j++ ){
            for( int k = j; k < z; k+=j ){
                dp[i][k] = (dp[i][k] % mod+dp[i-1][j]%mod)%mod;
            }
        }
    }
}

int TC;
int main()
{
    file_i_o();
    int n, k;
    memset(dp, 0, sizeof dp);
    pre();
    while ( cin >> n >> k )
    {
        int ans = 0;
        for( int i = 1; i <= n; i++ ){
            ans += dp[k][i];
            ans %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}


