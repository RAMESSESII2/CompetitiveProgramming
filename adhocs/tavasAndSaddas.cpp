#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
#define D(x)    cerr << __LINE__ << ": " #x " = " << (x) << '\n'
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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        string s;
        cin >> s;
        int x = 0;
        for( auto c: s ){
            if( c == '4' ) x = x*2+1;
            else x = x*2 + 2;
        }
        cout << x << endl;
    }
    return 0;
}


