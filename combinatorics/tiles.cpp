#include<bits/stdc++.h>
#include <ios>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
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
const int mod = 998244353;

ll binpow(ll a, ll b){
    ll ans = 1L;
    while( b>0 ){
        if( !(b&1) ){
            a *= a;
            a %= mod;
            b >>= 1;
        }
        ans *= a%mod;
        ans %= mod;
        b--;
    }
    return ans;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int w, h;
        cin >> w >> h;
        cout << binpow(2L, long(w+h)) << endl;
    }
    return 0;
}


