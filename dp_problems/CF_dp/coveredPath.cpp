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
int v1, v2, t, d;
int f;
int dp[200];
int solver(int ind, int prev){
    if( ind == t ) {
        if( abs(v2-prev) > d ) return -inf;
        else return v2;
    }
    int ans = -inf;
    for( int i = prev; i <= prev+d; i++ ){
        ans = max(ans, i+solver(ind+1, i));
    }
    return ans;
}


int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> v1 >> v2 >> t >> d;
        if( t == 2 ) {
            cout << v1+v2 << endl;
            break;
        }
        // if( v1 > v2 ) swap(v1, v2);
        int ans = 0;
        for( int i = 0; i <= t-1; i++ ){
            ans += min(v1+d*i, v2+d*(t-i-1));
        }
        cout << ans << endl;
    }
    return 0;
}


