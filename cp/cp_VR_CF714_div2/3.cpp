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

const int modd = (int)1e9+7;
int TC;
int dp[200009];
int main()
{
    file_i_o();
    cin >> TC;
    for( int i = 0 ; i <= 8; i++) dp[i] = 2;
    dp[9] = 3;
    for( int i = 10 ; i < 200009; i++) dp[i] = (dp[i-10] + dp[i-9])%modd;
    while (TC--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        while( n > 0 ){
            int num = n%10;
            ans += ((m+num < 10)? 1: dp[m-10+num]%modd)%modd;
            ans %= modd;
            n /= 10;
        }
        cout << ans%modd << endl;
    }
    return 0;
}


