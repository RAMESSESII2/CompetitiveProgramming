#include<bits/stdc++.h>
#include <ctime>
#include <iomanip>
#include <set>
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
        ll total = 0l;
        ll maxm = -inf;
        for( int i = 0; i < n ; i++ ){
            ll x;
            cin >> x;
            total += x;
            maxm = max(maxm, x);
        }
        cout << setprecision(9) << fixed << 1.0*(total-maxm)/(n-1)*1.0+maxm*1.0 << endl;
    }
    return 0;
}


