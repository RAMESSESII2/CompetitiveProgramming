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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        ll n; vl arr;
        cin >> n;
        arr.resize(n);
        for( auto  &x: arr) cin >> x;
        ll ans = 0l;
        vl odd;
        ll maxOfNeg = -inf;
        ll minOfPos = inf;
        for( int i = 0; i < n; i++ ){
            if( arr[i] >= 0 ){
                ans += arr[i];
            }
            if( (arr[i]&1 ) ){
                if( arr[i] < 0){
                    maxOfNeg = max(maxOfNeg, arr[i]);
                }
                else minOfPos = min(minOfPos, arr[i]);
            }
        }
        if(!(ans&1)){
            ans -= min(-maxOfNeg, minOfPos);
        }
        cout << ans << endl;
    }
    return 0;
}


