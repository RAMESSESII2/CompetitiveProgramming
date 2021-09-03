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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n+1);
        for( int i = 1; i <= n; i++ ) cin >> arr[i];
        int maxEleInd = *max_element(all(arr));
        int ans = 0l;
        for( int i = 1; i <= n; i++ ){
            if( arr[i] == maxEleInd ){
                // cerr << i << endl;
                if( i-k+1 > 0 ){
                    ans += 1l*(n-i+1);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}


