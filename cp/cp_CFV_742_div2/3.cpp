#include<bits/stdc++.h>
#include <limits>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)   r.begin(), r.end()
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
    cin >> TC;
    while (TC--)
    {
        string s;
        cin >> s;
        string l="0", r="0";
        for( int i = 0; i < (int)s.length(); i++ ){
            if( i&1 ) l += s[i];
            else r += s[i];
        }
        int fir = stoi(l);
        int sec = stoi(r);
        cout << (fir+1)*(sec+1) -2 <<endl;
    }
    return 0;
}


