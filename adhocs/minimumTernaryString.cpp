#include<bits/stdc++.h>
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

const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        string s;
        cin >> s;
        string ans;
        int count = 0;
        for( auto c: s ){
            if( c == '1'){
                count++;
                continue;
            } 
            else ans.push_back(c);
        }
        int found = ans.find("2");
        // cerr << found << endl;
        if( found != string::npos){
            cout << ans.substr(0, found) << string(count, '1') << ans.substr(found, (int)ans.size()-found);
        }
        else{
            cout << ans << string(count, '1');
        }
    }
    return 0;
}


