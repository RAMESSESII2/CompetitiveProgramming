#include<bits/stdc++.h>
#include <string>
#include <type_traits>
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
    cin >> TC;
    while (TC--)
    {
        int l, r;
        cin >> l >> r;
        auto calc = [](int n)->ll{
            ll ans = 0L;
            for( int i = 0; i < (int)to_string(n).length(); i++ ){
                int div = 1;
                for(int t = i; t > 0; t--)div *= 10;
                ans += n/div;
            }
            return ans;
        };
        cout << calc(r) - calc(l) << endl;
    }
    return 0;
}


