#include<bits/stdc++.h>
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

void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for( int j = 0; j < min(m, n); j++ ){
        string ans = s;
        if( s[0] == '0' ){
            if( 1<n && s[1] == '1' ) ans[0] = '1';
        }
        if( s[n-1] == '0' ){
            if( n-2>=0 && s[n-2] == '1' ) ans[n-1] = '1';
        }
        for( int i = 1; i < n-1; i++ ){
            if( s[i] == '0' ){
                if( (s[i-1] == '1' && s[i+1] == '0') || (s[i-1] == '0' && s[i+1] == '1') ){
                    ans[i] = '1';
                }
            }
        }
        s = ans;
    }
    cout << s << endl;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        solve();
    }
    return 0;
}


