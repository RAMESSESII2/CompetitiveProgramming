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
    cin >> TC;
    while (TC--)
    {
        string s;
        cin >> s;
        vector< vector<int> > lst(2, vector<int>(2, -1));
        ll ans = 0;
        for( int i = 0; i < (int)s.length(); ++i ){
            int j = i-1;
            int p = i&1;
            if( s[i] != '1' ) j = min(j, max(lst[0][p^1], lst[1][p]));
            if( s[i] != '0' ) j = min(j, max(lst[1][p^1], lst[0][p]));
            ans += i-j;
            if( s[i] != '?' ) lst[s[i]-'0'][p] = i;
        }
        cout << ans << endl;
    }
    return 0;
}


