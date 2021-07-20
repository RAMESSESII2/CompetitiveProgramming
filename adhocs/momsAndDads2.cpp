#include<bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

void file_i_o(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}

// string s;
string m, d;
vector<char> s;
ll dp[100005][4];

ll subseqCount(int m, int n, string cur){
    memset(dp, 0l, sizeof dp);

    for( int i = 0; i <= n ; i++ ) dp[0][i] = 0l;
    for( int i = 0; i <= m; i++ ) dp[i][0] = 1l;

    for( int i = 1; i <= m; i++){
        for( int j = 1; j <= n; j++){
            if( s[i-1] == cur[j-1] ){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[m][n];
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        char c;
        while( (scanf("%c", &c))==1) s.push_back(c);
        m = "MOM";
        d = "DAD";
        int l1 = (int)s.size();
        ll ans= 0l;
        ans += 1*subseqCount(l1, 3, m);
        ans += 1*subseqCount(l1, 3, d);
        printf("%lld", ans);
    }
}
