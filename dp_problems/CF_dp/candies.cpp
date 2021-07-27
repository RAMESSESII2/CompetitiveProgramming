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
const int maxm = 1e5+10;
vector<vector<pii>> dp;
int n;
vi arr;
void pre(){
    dp.assign(20, vector<pii>());
    for( int i = 0; i <= 19; i++ ){
        dp[i].assign(n+1, {0, 0});
    }
    for (int i = 0; i <= n; i++){
        dp[0][i] = {arr[i-1], 0};
    }
    for( int i = 1; i <= 19; i++  ){
        if( (1<<i) > n ) break;
        for( int j = 1; j <= n ;j++ ){
            if( (j + (1<<(i-1))) > n ) break;
            dp[i][j].first = dp[i-1][j].first+dp[i-1][j+(1<<(i-1))].first;
            if( dp[i][j].first >= 10 ) dp[i][j].second = 1;
            dp[i][j].first %= 10;
            dp[i][j].second += dp[i-1][j].second+dp[i-1][j+(1<<(i-1))].second;
        }
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        arr.resize(n);
        for( auto &x: arr ) cin >> x;
        pre();
        int q;
        cin >> q;
        // for( int i = 0; i < 5; i++){
        //     for( int j = 0; j < n+1; j++){
        //         cerr << dp[i][j].first << " " << dp[i][j].second  << "      ";
        //     }
        //     cerr <<endl;
        // }
        for( int i = 0; i < q; i++){
            int l, r;
            cin>> l >> r;
            int k = 0;
            int cur = r-l+1;
            while( (1<<k) != cur ) {
                k++;
            }
            // cerr << l << " " << k << endl;
            cout << dp[k][l].second << endl;
        }
    }
    return 0;
}


