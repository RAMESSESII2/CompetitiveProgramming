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
    cin >> TC;
    while (TC--)
    {
        string s;
        cin >> s;
        int n = (int)s.length();
        const int mod = (int)1e9+7;
        ll ans = 0L;
        ll c = 0L;
        for( int i = n-1; i >= 0; i-- ){
            if( s[i] == 'b' ){
                c++;
            }
            else{
                ans += c;
                c <<= 1l;
            }
            ans %= mod;
            c %= mod;
        }
        cout << ans << endl;
    }
    return 0;
}


