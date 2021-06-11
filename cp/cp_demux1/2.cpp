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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        string s;
        cin >> s;
        map<int, int> mp;
        for( auto x: s ){
            mp[x]++;
        }
        int n = (int)s.length();
        bool t =true;
        for( int i = 0; i < n/2; i++){
            if( s[i] != s[n-i-1] ){
                t = false;
                break;
            }
        }
        if( t ){
            cout << "YES";
        }
        else cout << "NO";
    }
    return 0;
}

