#include<bits/stdc++.h>
#include <vector>
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
int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n, m;
        cin >> n >> m;
        map<string, int> names;
        vector<string> na(n);
        string s, t;
        for( int i = 0; i < n; i++ ){
            cin >> s;
            na[i] = s;
            names[s] = i;
        }
        vector<vector<bool>> good(n, vector<bool> (n, 1));
        for( int i = 0; i < m; i++ ){
            cin >> s >> t;
            good[names[s]][names[t]] = 0;
            good[names[t]][names[s]] = 0;
        }
        int nax = 0;
        int best = 0;
        bool ok;
        for( int mask = 0; mask < (1<<n); mask++ ){
            ok = 1;
            for(int i = 0; i < n; i++){
                if( mask&(1<<i) ){
                    for( int j = 0; j < n; j++ ){
                        if( mask&(1<<j) ){
                            if(!good[i][j]){ 
                                ok =false;
                                break;
                            }
                        }
                    }
                }
            }
            if( ok && __builtin_popcount(mask) > nax ){
                best = mask;
                nax = __builtin_popcount(mask);
            }
        }
        set<string> out;
        for(int i = 0; i < n; i++){
            if( best&(1<<i) ){
                out.insert(na[i]);
            }
        }
        cout << nax << endl;
        for( auto x: out ) cout << x << endl;
    }
    return 0;
}


