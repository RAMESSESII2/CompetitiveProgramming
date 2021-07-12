#include<bits/stdc++.h>
#include <typeindex>
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
const int modd = 998244353;

template<typename T, typename S>
T mxm(T x, S y){
    return (x>y)?x:y;
}


int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        int p = -1;
        int ans = 1;
        ll sum = 0L;
        int a;
        for( int i = 0; i < n; i++ ){
            cin >> a;
            if( a >= n-k+1 ){
                if( p!=-1 ) ans = 1LL*ans*(i-p)%modd;
                sum += a;
                p = i;
            }
        }
        cout << sum << " " << ans << endl;
    }
    return 0;
}


