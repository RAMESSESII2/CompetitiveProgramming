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
int dp[10][2][80][80];

ll recurse(int ind, bool e, int evensum, int oddsum){
    if( ind == n ){
        return (evensum-oddsum == 1);
    }
    if( dp[ind][e][evensum][oddsum] != -1 ){
        return dp[ind][e][evensum][oddsum];
    }
    int limit = (e? s[ind]-'0': 9);
    ll ans = 0L;
    for( int i = 0; i <= limit; i++){
        int newE = ((s[ind]-'0') == i) ? e: 0;
        if(ind&1) oddsum+=i;
        else evensum+=i;
        ans += recurse(ind+1, oddsum, evensum, newE);
    }
    dp[ind][e][evensum][oddsum] = ans;
    return ans;
}

ll solve(int r){
    ll ans;
    s = to_string(r);
    n = (int)s.size();
    memset(dp, -1, sizeof dp);
    ans = recurse(0, 1, 0, 0);
    return ans;
}

int TC;
int main()
{
    file_i_o();
    int ans = 0;
    for( int i = 10 ; i <= 1000; i++ ){
        int sum = 0;
        string s = to_string(i);
        for( int j = 0; j < (int)s.size(); j++  ){
            if( j&1 ) sum += (s[j]-'0');
            else sum -= (s[j]-'0');
        }
        if( sum == 1 ) ans++;
    }
    cout << ans << endl;
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


