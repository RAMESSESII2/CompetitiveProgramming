#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

string minWindow(string s, string t){
    int n, m;
    m = (int)s.length();
    n = (int)t.length();
    unordered_map<char, int> mp;
    for( auto ch: t ){
        mp[ch]++;
    }
    unordered_map<char, int> reqMp;
    int len = inf;
    pair<int,int> ans = {-1, -1};
    int l = 0, r = 0;
    int reqCount = 0;
    while(1){
        bool fir = true;
        bool sec = true;
        // acquire while we need to
        while(r < m && reqCount < n ){
            reqMp[s[r]]++;
            if( mp[s[r]] >= reqMp[s[r]] ){
                reqCount++;
            }
            r++;
            fir =false;
        }

        // collect answere and then release starting point to get optimized answer
        while(l < r  && reqCount == n){
            if(len > r-l+1){
                len = r-l+1;
                ans = {l, r};
            }
            reqMp[s[l]]--;
            if( reqMp[s[l]] < mp[s[l]] ){reqCount--;}
            l++;
            sec =false;
        }
        if( fir && sec ) break;
    }
    if( len == inf ) return "";
    else return s.substr(ans.first, len-1);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        string s, t;
        cin >> s >> t;
        cout << minWindow(s, t) << endl;
    }
    return 0;
}


