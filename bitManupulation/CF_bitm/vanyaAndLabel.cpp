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

const int inf = (int)1e9+7;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {

        string s;
         cin >> s;
        vector<char> pattern;
        for( int i = '0'; i<='9'; i++){
            pattern.push_back(i);
        }
        for( int i = 'A'; i<='Z'; i++){
            pattern.push_back(i);
        }
        for( int i = 'a'; i<='z'; i++){
            pattern.push_back(i);
        }
        pattern.push_back('-');
        pattern.push_back('_');
        map<char, int> value;
        for(int i = 0; i < 64; i++){
            value[pattern[i]] = i;
        }
        ll ans = 1l;
        for( auto x: s ){
            int val = value[x];
            for( int i = 5; i >= 0; i--  ){
                if(!( (1<<i)&val )){
                    ans *= 3l;
                    ans %= inf;
                }
            }
        }
        cout << ans%inf << endl;
    }
    return 0;
}


