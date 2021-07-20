#include <algorithm>
#include<bits/stdc++.h>
#include <cstring>
#include <math.h>
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

const ll inf = -static_cast<ll>(1e18);
int n, q;
vl power;
ll dpOdd[300005];
ll dpEven[300005];


int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n >> q;
        power.assign(n, 0l);
        for( auto &x: power) cin >> x;
        memset(dpOdd, 0l, sizeof dpOdd);
        memset(dpEven, 0l, sizeof dpEven);
        dpOdd[0] = inf;
        ll ans = 0;
        for( int i = 0; i < n; i++){
            dpOdd[i+1] = max(dpOdd[i], dpEven[i]+power[i]);
            dpEven[i+1] = max(dpEven[i], dpOdd[i]-power[i]);
            ans = max({ans, dpEven[i+1], dpOdd[i+1]});
        }
        cout << max(dpEven[n], dpOdd[n]) << endl;
    }
    return 0;
}


