#include<bits/stdc++.h>
#include <numeric>
#include <string>
using namespace std;
#define ll long long int

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

bool prime[85];
int n;
string s;
ll dp[10][85][2];

ll find(int len, int sum, int e){
    if( len == n){
        return prime[sum];
    } 
    if( dp[len][sum][e] != -1 ){
        return dp[len][sum][e];
    }
    ll ans = 0;
    int lim = (e? s[len]-'0': 9);
    for( int d = 0; d <= lim; d++ ){
        int nxtE = ((d == (s[len]-'0'))?e:0);
        ans += find(len+1, sum+d, nxtE);
        // cerr << ans << endl;
    }
    dp[len][sum][e] = ans;
    return ans;
}

ll gone(int v){
    ll ans;
    n = (int)(to_string(v).size());
    s = to_string(v);
    memset(dp, -1, sizeof dp);
    // cerr << n << " " << s << endl;
    ans = find(0, 0, 1);
    // cout << ans << endl;
    return ans;
}

int TC;
int main()
{
    file_i_o();
    prime[0] = prime[1] = 0;
    for( int i = 2; i < 85; i++ ){
        prime[i] = 1;
        for( int j = 2; j < i; j++ ){
            if( i%j == 0 ) prime[i] = 0;
        }
    }
    cin >> TC;
    while (TC--)
    {
        int l, r;
        cin >> l >> r;
        ll ans = gone(r)-gone(l-1);
        cout << ans << endl;
    }
    return 0;
}


