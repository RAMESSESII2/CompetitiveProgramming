#include <algorithm>
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

const int inf = INT_MAX;
const int mod = 998244353;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n ;
        cin >> n;
        vector<int> arr(n);
        for(int &x: arr) cin >> x;
        int mx = *max_element(all(arr));
        int cmx = count(all(arr), mx);
        int k = count(all(arr), mx-1);
        int ans = 1, sub = 1;
        for(ll i = 1l; i <= n; i++){
            ans = (ans*i)%mod;
            if( i != k+1 ) sub = sub*i%mod;
        }
        if( cmx == 1 ) ans =(ans-sub+mod)%mod;
        cout << ans << endl;
    }
    return 0;
}


