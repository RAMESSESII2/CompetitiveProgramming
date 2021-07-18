#include<bits/stdc++.h>
#include <vector>
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
int p, q, s, n;
map<pair<int, int>, int> mp;
pii ans;

int minmSteps(int fir, int sec, int c){
    if( c >= s ) return 0;
    if( fir > p or sec > q ) return 0;
    if( mp[make_pair(fir,sec)] == 0 ){
        ans = min(ans, {abs(n-(fir+sec)), c});
        mp[ make_pair(fir,sec) ] = 1;
        return minmSteps(0, sec, c+1) || minmSteps(fir, 0, c+1) || minmSteps(p, sec, c+1)|| minmSteps(fir, q, c+1) || minmSteps(fir+min(sec, (p-fir)), sec-min(sec,(p-fir) ), c+1)|| minmSteps(fir-min(fir, (q-sec)), sec+min(fir, (q-sec)), c+1);
    }
    return 0;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> p >> q >> s >> n;
        mp.clear();
        ans = {inf, inf};
        minmSteps(0, 0, 0);
        // cout << ans.first << " " << ans.second;
        // 
        cout << ans.first;
    }
    return 0;
}


