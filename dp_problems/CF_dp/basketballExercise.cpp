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
// here we can choose either previous one or prev to prev one from the other row 

const int inf = INT_MAX;
const int maxm = (int)1e5+9;
int n;
ll dp[3][maxm];

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        cin >> n;
        vl h1(n);
        vl h2(n);
        for( auto &x: h1 ) cin >> x;
        for( auto &x: h2 ) cin >> x;
        memset(dp, 0, sizeof dp);
        dp[1][1] = h1[0];
        dp[2][1] = h2[0];
        for( int i = 2; i <= n; i++ ){
            dp[1][i] = max(dp[2][i-1], dp[2][i-2]) + h1[i-1];
            dp[2][i] = max(dp[1][i-1], dp[1][i-2]) + h2[i-1];
        }
        cout << max(dp[1][n], dp[2][n]) << endl;
    }
    return 0;
}


