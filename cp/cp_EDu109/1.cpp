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

ll gcd(ll a, ll b){
    while( 1 ){
        if( a == 0) return b;
        b %= a;
        if( b == 0 ) return a;
        a %= b;
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int k;
        cin >> k;
        int ans = (100-k);
        int g = gcd(ans, k);
        cout << ans/g + k/g << endl;
    }
    return 0;
}


