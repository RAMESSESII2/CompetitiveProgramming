#include <algorithm>
#include<bits/stdc++.h>
#include <mutex>
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
int n;
int a, b, c;
int dp[4010];

int maxRibbons(int r){
    if( r < 0 ) return -inf;
    if( r == 0 ) return 0;
    if( dp[r] != -1 ) return dp[r];
    return dp[r] = 1+max({maxRibbons(r-a), maxRibbons(r-b), maxRibbons(r-c)});
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        cin >> a >> b >> c;
        memset(dp, -1, sizeof dp);
        cout << maxRibbons(n);
    }
    return 0;
}


