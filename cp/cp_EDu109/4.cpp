#include <algorithm>
#include<bits/stdc++.h>
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

const int inf = (int)1e9;
int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for( auto &x: arr ) cin >> x;
        vector<int> pos;
        for( int i = 0; i < n; i++){
            if( arr[i] == 1 ){
                pos.push_back(i);
            }
        }
        int k = (int)pos.size();
        vector<vector<int> > dp(n+1, vector<int> (k+1, inf));
        dp[0][0] = 0;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j <= k; j++){
                if( dp[i][j] == inf ) continue;
                dp[i+1][j] = min( dp[i+1][j], dp[i][j] );
                if( j < k && arr[i] == 0){
                    dp[i+1][j+1] = min( dp[i+1][j+1], dp[i][j] + abs(pos[j] - i) );
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}


