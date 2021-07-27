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
//if the string contains w or m then return 0;
//else
//multiplying independent values that can be made with all u's and n's over all sequences of only u and only n
//if u or n is alone then it's 1
//we follow fibonacci seq n= 2 = fib 2, n= 3 = fib 3, n= 4 = fib 5 --> observable answer
//or we can make a dp soln
//dp[i] = dp[i-1] + dp[i-2] (if s[i] == s[i-1] == n or u)

const int inf = INT_MAX;
const int modd = (int)1e9+7;
string s;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        cin >> s;
        ll dp[(int)1e5+3];
        int n= (int)s.length();
        bool c = 1;
        for( auto x: s) {
            if( x == 'm' || x == 'w' ){
                cout << 0 << endl;
                c = 0;
                break;
            }
        }
        if(!c) continue;
        memset(dp, 0l, sizeof dp);
        dp[0] = dp[1] = 1l;
        for( int i = 2; i <= n; i++){
            dp[i] = dp[i-1]%modd;
            if( s[i-1] == s[i-2] && (s[i-1] == 'u' || s[i-1] == 'n' )){
                dp[i]  +=   dp[i-2]%modd;
            }
            dp[i] %= modd;
        }
        cout << dp[n] << endl;
    }
    return 0;
}


