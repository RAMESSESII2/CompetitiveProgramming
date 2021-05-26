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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        string a, b;
        cin >> a >> b;
        int n = (int)a.length();
        int m = (int)b.length();
        int pref[200009+1][2];
        memset(pref, 0, sizeof pref);
        for( int i = 1; i <= m; i++ ){
            for( int j = 0; j < 2; j++ ){
                pref[i][j] = pref[i-1][j];
            }
            pref[i][b[i-1]-'0']++;
        }
        ll ans = 0;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j <= 1; j++ ){
                ans += (abs((a[i]-'0')-j)*abs(pref[ m-n+i+1 ][ j ] - pref[i][j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}


