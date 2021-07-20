#include<bits/stdc++.h>
#include <cstring>
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
int N;
string S;
string comp;
ll dp[(int)1e6+10][4];

ll ans(int n, int m){
    if( m == 0 ) return 1;
    if( n == 0) return 0;
    if( dp[n][m] != -1 ) return dp[n][m];
    auto &ret = dp[n][m];
    if( S[n-1] == comp[m-1]){
        ret =  ans(n-1, m)+ans(n-1, m-1);
    }
    else ret =  ans(n-1, m);
    return ret;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        string s;
        comp = "wow";
        cin >> s;
        int n = (int)s.length();
        int cnt = 0;
        S = "";
        for( int i = 1; i < n; i++){
            if(s[i]== 'v'){if (s[i] == s[i-1]) cnt++;}
            else{
                S += string(cnt, 'w');
                S += s[i];
                cnt = 0;
            }
        }
        S += string(cnt, 'w');
        N = (int)S.length();
        memset(dp, -1, sizeof dp);
        cout << ans(N, 3) << endl;
         /* 
            string s;
            cin >> s
            ll a = 0, b = 0, c= 0;
            for( int i = 0; i  < s.size(); i++ ){
                if(s[i] == 'o') b+=a;
                else if ( i > 0 && s[i-1] == 'v'){
                    a++;
                    c += b;
                }
            }
            cout << c << endl;
         */
    }
    return 0;
}


