#include<bits/stdc++.h>
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

int n;
string s;
int dp[10][85][2];

ll recurse(int ind, ll sum, bool e){
    if( ind == n ){
        return sum==1L;
    }
    if( dp[ind][sum][e] != -1 ){
        return dp[ind][sum][e];
    }
    int limit = (e? s[ind]-'0': 9);
    ll ans = 0L;
    for( int i = 0; i <= limit; i++){
        int newE = ((s[ind]-'0') == i) ? e: 0;
        ans += recurse(ind+1, (ind&1)? sum-i: sum+i, newE);
    }
    dp[ind][sum][e] = ans;
    return ans;
}

ll solve(int r){
    ll ans;
    s = to_string(r);
    n = (int)s.size();
    memset(dp, -1, sizeof dp);
    ans = recurse(0, 0, 1);
    return ans;
}

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int l, r;
        cin >> l >> r;
        ll ans = solve(r)-solve(l-1);
        cout << ans << endl;
    }
    return 0;
}


