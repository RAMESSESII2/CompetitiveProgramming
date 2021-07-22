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
string s;
int n;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> s;
        n = (int)s.length();
        ll ans = 0l;
        for( auto x: s ){
            if( (x-'0') % 4 == 0) ans+=1l;
        }
        for( int i = 1; i < n; i++ ){
            if( (10*(s[i-1]-'0') + (s[i]-'0') )%4 == 0){
                ans += 1l*i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


