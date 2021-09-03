
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
        ll n, x, y;
        string s;
        cin >> n >> s >> x >> y;
        // number of titans which should face Westward
        vl west(n+1);
        // number of titans which should face Eastward
        vl east(n+1);
        //to make them look to their east
        for(int i = 0; i < n; i++){
            if( s[i] == 'E' ){
                east[i+1] = 1l*east[i];
            }
            else if( s[i] == 'W' ){
                east[i+1] = 1l*(east[i] + min(2*x, 2*y));
            }
            else if( s[i] == 'S' ){
                east[i+1] = 1l*(east[i] + min(y, 3*x));
            }
            else east[i+1] = 1l*(east[i] + min(x, 3*y));
        }
        //to make them look to their west
        for(int i = n-1; i >= 0; i--){
            west[i] = 1l*west[i+1];
            if( s[i] == 'E' ){
                west[i] += 1l*min(2*x, 2*y);
            }
            else if( s[i] == 'S' ){
                west[i] += 1l*min(x, 3*y);
            }
            else if( s[i] == 'N' ){
                west[i] += 1l*min(y, 3*x);
            }
        }
        // for( auto x: east ) cerr << x<<" ";
        // cerr << endl;
        // for( auto x: west ) cerr << x<<" ";
        // cerr << endl;
        ll ans = inf;
        for( int i = 0; i <= n; i++ ){
            ans = min(ans, west[i]+east[i]);
        }
        cout << ans << endl;
    }
    return 0;
}


