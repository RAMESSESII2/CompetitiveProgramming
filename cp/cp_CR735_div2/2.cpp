#include<bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
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

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n+1);
        for( int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int ans = -INT_MAX;
        int l = max(1, n-2*k);
        for( int i = l; i  <= n ;i++ ){
            for( int j = i+1; j  <= n ;j++ ){
                ans = max(ans, i*j - k*(arr[i] | arr[j]));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}


