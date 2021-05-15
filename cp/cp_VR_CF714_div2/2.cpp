#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
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
const int modd = (int)1e9+7;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for( ll &x : arr) cin >> x;
        ll minm = *min_element(arr.begin(), arr.end());
        bool ex = false;
        ll count = 0;
        // cerr << minm << endl;
        for( auto x: arr ){
            if( (minm&x) != minm ){
                ex = true;
                break;
            }
            if( x == minm ) count++;
        }
        if( ex || count == 1) {
            cout << 0 << endl;
            continue;
        }
        ll fact = 1L;
        for( ll i = 1L; i <= n-2L; i++ ) fact = (1L*fact*i)%modd;
        ll ans = (1LL* count*(count-1))%modd;
        ans = (fact*1L*ans)%modd;
        cout << ans%modd << endl;
    }
    return 0;
}


