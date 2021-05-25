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

const int MAX = (int)1e5+5;
const int mod = (int)1e9+7;
int TC;
ll binPow(ll a, ll b){
    ll res = 1L;
    while( b > 0 ){
        if( b&1 ){
            res *= a%mod;
            res %= mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        ll n;
        cin >> n;
        ll ans = binPow(2L, n-1);
        cout << ans << endl;
    }
    return 0;
}


