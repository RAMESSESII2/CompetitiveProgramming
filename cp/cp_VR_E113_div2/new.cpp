#include<bits/stdc++.h>
using namespace std;
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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        string s;
        int n;
        cin >> s >> n;
        if( s[0] == 'm' ) n+= 1;
        else if( s[0] == 't' && s[1] == 'u' ) n+= 2;
        else if( s[0] == 'w' ) n+= 3;
        else if( s[0] == 't' && s[1] == 'h' ) n+= 4;
        else if( s[0] == 'f' && s[1] == 'r' ) n+= 5;
        else if( s[0] == 's' && s[1] == 'a' ) n+= 6;
        cout << n/7 << endl;
    }
    return 0;
}


