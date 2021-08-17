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
        int N, k;
        cin >> N >> k;
        vi arr(N+1);
        for( int i = 1; i <= N; i++ ){
            cin >> arr[i];
        }
        vi dp(N+1, 0);
        for( int i = 1; i <= N; i++ ){
            dp[i] = dp[arr[i]];
            int ref = arr[i]+k;
            if( arr[i] == 0 || ref < i ){
                dp[i]++;
            }
            if( arr[i] == 0 ){
                dp[i] += min(i-1, k) + min(N-i, k);
            }
            else {
                dp[i] += max(min(i-ref-1, k), 0) + max(min(N-max(ref, i), k-max(ref-i, 0)), 0);
            }
            cout << dp[i] << " ";
        }
    }
    return 0;
}


