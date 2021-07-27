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
    // cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = "";
        int ans = 0;
        map<char, int> mp;
        mp['B'] = 0;
        mp['G'] = 1;
        mp['R'] = 2;
        t += s[0];
        for(int i = 1; i < n; i++){
            if( s[i] == s[i-1] ){
                int cur = (mp[s[i]]+1)%3;
                char c = (cur == 0? 'B':(cur == 1 ? 'G': 'R'));
                if( i < n-1 && c == s[i+1] ){
                    cur += 1;
                    cur %= 3;
                }
                c = (cur == 0? 'B':(cur == 1 ? 'G': 'R'));
                t += c;
                s[i] = t.back();
                ans++;
            }
            else t+=s[i];
        }
        cout << ans << endl;
        cout << t << endl;

    }
    return 0;
}


