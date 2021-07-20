#include<bits/stdc++.h>
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

const int inf = (int)1e9;
const int N = (int)1e5+5;
ll dp[N][2];
string s;
int A, B;

ll solve(int ind, int active){
    if( ind == (int)s.size()) return 0;
    //if already computed then return
    auto &ret = dp[ind][active];
    if( ~ret ) return ret;
    //if current building has a mine
    if( s[ind] == '1' ) {
        //if previous one is activated then I'm not paying anything, else I'm goona pay A and activate it and the next one will not be needed to be activated
        ret = solve(ind+1, 1) + ((!active)?A:0);
    }
    //if building doesnt have a mine
    //then I can either put one and then activate it, or not put one
    else{
        //not putting one
        ret = solve(ind +1, 0);
        //put one payng B and then activate it if previous one is not activated paying A, else leave dont pay anything
        ret = min(ret, solve(ind+1, 1) + ((!active)? A: 0) +B);
    }
    return ret;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> A >> B;
        cin >> s;
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << endl;
    }
    return 0;
}


