#include<bits/stdc++.h>
#include <exception>
#include <string>
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
set<string> ans;
int n, q;
map<string, string> ops;

void backTrack(string t, string prev){
    int len = (int)t.size();
    if( len == n && prev == "a") ans.insert(t); 
    if( len >= n ) return void();
    for( int i = 0; i < 6; i++ ){
        string p = prev +char('a'+i);
        // cerr <<t+char('a'+i) << " " << ops[p] << endl;
        backTrack(t+char('a'+i) , ops[p]);
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n >> q;
        ops.clear();
        string a, b;
        for( int i = 0; i < q; i++){
            cin >> a >> b;
            ops[a] = b;
        }
        ans.clear();
        for( auto [x, y]: ops){
            // cerr << x << " " << y << endl;
            backTrack(x, y);
        }
        // for( auto x: ans ) cout << x << endl;
        cout << (int)ans.size() << endl;
    }
    return 0;
}


