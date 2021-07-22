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
//2 different color -> 3rd color
//2 same color -> 1 same color
//Observations
// 1 =>if only one kind is availabe -> only 1 choice
// 2 => if all color are available -> all choices
// 3 => any two different kinds are available
const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<char, int> mp;
        for( auto x: s ) mp[x]++;
        if( mp.size() == 1 ){
            for(auto x: mp) cout << x.first;
        }
        else if( mp.size() == 3 ){
            cout << "BGR";
        }
        else{
            bool two = true;
            for(auto x: mp){
                if( x.second < 2) two = false;
            }
            if( two ) cout << "BGR";
            else{
                bool one = true;
                for( auto x: mp ){
                    if( x.second > 1) one = false;
                }
                if( one ){
                    if( mp['R'] && mp['G'] ) cout << "B";
                    else if( mp['B'] && mp['R'] ) cout << "G";
                    else cout << "R";
                }
                else{
                    if( mp['R'] && mp['G'] ) cout << "B" << (mp['R']>mp['G'] ? 'G':'R');
                    else if( mp['B'] && mp['G'] ) cout << (mp['B']>mp['G'] ? 'G':'B') <<"R";
                    else {
                        if( mp['R'] > mp['B'] ){
                            cout << "BG" ;
                        }
                        else cout << "GR";
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}


