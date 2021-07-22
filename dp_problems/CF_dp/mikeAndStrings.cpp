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
string s[100];
int dp[200][200];

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++) cin >> s[i];
        int k = s[1].length();
        for( int i = 1; i <= n; i++ ){
            for( int j = 0; j < k; j++ ) dp[i][j] = 1e9;
        }
        for( int i = 1; i <= n; i++) s[i] = s[i]+s[i];
        for( int i = 0; i < k; i++) dp[1][i] = i;
        for( int i = 2; i <= n; i++ ){
            for( int j = 0; j < k; ++j){
                for( int prev = 0; prev < k; ++prev){
                    if (s[i].substr(j, k) == s[i-1].substr(prev, k)){
                        dp[i][j] = min(dp[i][j], dp[i-1][prev] + j);
                    }
                }
            }
        }
        int ans = 1e9;
        for( int i = 0; i < k; ++i)ans = min(ans, dp[n][i]);
        if( ans == 1e9 ) puts("-1");
        else cout << ans << endl;
    }
    return 0;
}


