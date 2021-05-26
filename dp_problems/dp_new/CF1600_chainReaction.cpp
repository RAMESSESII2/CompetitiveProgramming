#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <vector>
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

const int maxm = (int)1e6+9;
int dp[maxm];
int b[maxm];
int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        for(int i = 0, a; i < n; i++) cin >> a >> b[a];
        if( b[0] > 0 ) dp[0] = 1;
        int mx = 0;
        for( int i = 1; i < maxm; i++ ){
            if( b[i] == 0 ) dp[i] = dp[i-1];
            else{
                if( b[i] >= i ) dp[i] = 1;
                else dp[i] = dp[i-b[i]-1] + 1;
            }
            if( dp[i] > mx) mx = dp[i];
        }
        cout << n-mx << endl;
    }
    return 0;
}


