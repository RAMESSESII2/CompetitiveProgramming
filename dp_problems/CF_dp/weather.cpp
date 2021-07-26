#include<bits/stdc++.h>
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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n ;
        vi arr(n);
        int count = 0;
        for( auto &x: arr ){ 
            cin >> x;
        }
        vi minus(n+1), plus(n+1);
        for( int i = 0; i < n; i++ ){
            minus[i+1] = minus[i] + (arr[i] <= 0);
        }
        for( int i = 0; i < n; i++ ){
            plus[i+1] = plus[i] + (arr[i] >= 0);
        }
        int ans = inf;
        for( int i = 2; i <= n; i++){
            int need = plus[i-1] + minus[n] - minus[i-1];
            ans = min(ans, need);
        }
        // for( auto x: minus) cerr << x << " ";
        // cerr << endl;
        // for( auto x: plus) cerr << x << " ";
        cout << ans << endl;
    }
    return 0;
}


