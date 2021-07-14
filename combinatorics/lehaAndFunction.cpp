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
        cin >> n;
        vector<pair<int, int> > a(n);
        vector<pair<int, int> > b(n);
        for( int i = 0; i < n ; i++ ){
            cin >> a[i].first;
            a[i].second = i;
        }
        for( int i = 0; i < n ; i++ ){
            cin >> b[i].first;
            b[i].second = i;
        }
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        // for( auto [x, y]: a ) cerr << x << " ";
        // cerr << endl;
        // for( auto [x, y]: b ) cerr << x << " ";
        // cerr << endl;
        vi ans(n);
        for( int i = 0; i < n; i++){
            ans[b[i].second] = a[i].first;
        }
        for( auto x: ans ) cout << x << " ";
        cout << endl;
    }
    return 0;
}


