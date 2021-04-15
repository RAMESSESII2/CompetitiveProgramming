#include<bits/stdc++.h>
#include <vector>
#define ll long long int
using namespace std;

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
const int mod = 1e9+7;
int n;
vector<int> arr;
ll dp[100005];
ll temp[100005];

int main()
{
    file_i_o();
    {
        cin >> n;
        arr.resize(n);
        for( auto &x : arr ) cin >> x;
        fill(dp, dp+n+1, 0);
        fill(temp, temp+n+1, 0);
        dp[0] = 1;
        ll sum = 0;
        for( int i = 0; i < n-1; i++){
            temp[i+1] = (temp[i+1] + dp[i]) %mod;
            if( i + 1 + arr[i] < n) temp[i+1+arr[i]] = (mod+temp[i+1+arr[i]] - dp[i]) %mod;
            sum = (sum+ temp[i+1] )%mod;
            dp[i+1] = sum;
        }
        cout << dp[n-1];
    }
    return 0;
}

