#include<bits/stdc++.h>
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


int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int ind = 0;
        int eng = 0;
        for(int i = 0;i < 5; i++){
            int x;
            cin >> x;
            if( x == 1) ind++;
            if( x == 2 ) eng++;
        }
        if( ind == eng) cout << "DRAW";
        else if ( ind > eng) cout << "INDIA";
        else cout << "ENGLAND";
        cout << "\n";
    }
    return 0;
}



