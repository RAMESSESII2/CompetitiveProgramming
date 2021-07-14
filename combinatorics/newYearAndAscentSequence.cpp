#include <algorithm>
#include<bits/stdc++.h>
#include <vector>
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
    while (TC--)
    {
        int n;
        cin >> n;
        vector< vector<int> > arr(n);
        for( int i = 0; i < n; i++){
            int size;
            cin >> size;
            arr[i].resize(size);
            for( auto &x: arr[i] ) cin >> x;
        }
        vector<pii> pr;
        for( int i =0; i < n; i++){
            reverse(arr[i].begin(), arr[i].end());
            if( is_sorted(arr[i].begin(), arr[i].end())){
                pr.emplace_back(arr[i][0], arr[i].back());
            }
        }
        sort(pr.begin(), pr.end());
        for( auto [x, y]: pr ) cerr << x << " " << y << endl;
        ll ans = 1LL*n*n;
        for( int i = 0; i < (int)pr.size(); i++ ){
            ans -= pr.end()-lower_bound(pr.begin(), pr.end(), pair<int, int>(pr[i].second, -1));
        }
        cout << ans << endl;
    }
    return 0;
}


