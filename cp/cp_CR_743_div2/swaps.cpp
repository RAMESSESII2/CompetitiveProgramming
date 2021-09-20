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
        int n;
        cin >> n;
        int a[n], pre[n];
        for( int i = 0; i < n; i++) cin >> a[i];
        for( int i = 0; i < n; i++){
            cin >> pre[i];
            if(i-1 >= 0) pre[i] = max(pre[i], pre[i-1]);
        }
        int ans = inf;
        for( int i = 0; i < n; i++){
            int j = lower_bound(pre, pre+n, a[i])-pre;
            if( j < n ) ans = min(ans, i+j);
        }
        cout << ans << endl;
    }
    return 0;
}


