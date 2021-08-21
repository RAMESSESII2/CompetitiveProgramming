#include<bits/stdc++.h>
#include <random>
#include <string>
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
int dp[20][20];
string a, b;
int na, nb;

int editDist(int indA, int indB){
    if( indA == 0 ) return indB;
    if( indB == 0 ) return indA;
    int &ans =  dp[indA][indB];
    if( ans != -1 ) return ans;
    if( a[indA-1] == b[indB-1] ){
        return ans = editDist(indA-1, indB-1);
    }
    return ans = 1+min(editDist(indA-1, indB), editDist(indA, indB-1));
}



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
        int ans = inf;
        for( ll i = 1l; i <= (ll)2e18; i*=2l ){
            memset(dp, -1 , sizeof dp);
            a = to_string(n);
            b = to_string(i);
            na = (int)a.size();
            nb = (int)b.size();
            int cur = editDist(na, nb);
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}


