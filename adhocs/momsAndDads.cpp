#include<bits/stdc++.h>
#include <string>
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
string s, m, d;
int dp[100005][3];

ll subseqCount(int m, int n, string cur){
    if( (m == 0 && n==0 ) || n == 0) return 1L;
    if( m <= 0 || n <= 0 ) return 0l;
    if( dp[m][n] != -1 ) return dp[m][n];
    if( s[m-1] == cur[n-1] ){
        return dp[m][n] = 1l*(subseqCount(m-1, n-1, cur) + subseqCount(m-1, n, cur));
    }
    else return dp[m][n] = 1l*subseqCount(m-1, n, cur);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> s;
        m = "MOM";
        d = "DAD";
        int l1 = (int)s.length();
        int l2 = (int)m.length();
        int l3 = (int)d.length();
        ll ans= 0l;
        memset(dp, -1, sizeof dp);
        ans += subseqCount(l1, l2, m);
        memset(dp, -1, sizeof dp);
        ans += subseqCount(l1, l3, d);
        cout << ans;
    }
}
