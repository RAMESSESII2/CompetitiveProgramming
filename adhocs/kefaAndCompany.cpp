#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <iterator>
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
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int N, d;
        cin >> N >> d;
        vector<pair<int, ll>>frnd(N);
        for( auto &[x, y]: frnd ){
            cin >> x >> y;
        }
        sort(frnd.begin(), frnd.end());
        // for( auto &[x, y]: frnd ){
        //     cerr  << x << " "  << y << endl;
        // }
        // cerr << endl;
        ll best = 0L;
        int l = 0,  r = 0;
        int low = INT_MIN;
        ll run = 0;
        vector<ll> sum(N+1, 0L);
        int i = 1;
        for( auto [x, y] : frnd ){
            sum[i] += sum[i-1]+y;
            // cerr << sum[i] << " " ;
            i++;
        }
        // cerr << endl;
        for( int i = 0; i < N; i++ ){
            pair<int, ll> f = {frnd[i].first+d, -868};
            auto j = lower_bound(frnd.begin()+i+1, frnd.end(), f);
            if( j == frnd.end() or j->first - frnd[i].first >= d ) j--;
            // cerr << j-frnd.begin()+1 << endl;
            best = max(best, sum[j-frnd.begin()+1]-sum[i]);

        }
        // cerr << endl;
        cout << best << endl;
    }
    return 0;
}


