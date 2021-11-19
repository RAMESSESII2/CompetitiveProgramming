#include<bits/stdc++.h>
using namespace std;

#define all(r)   r.begin(), r.end()
using vi = vector<int>;

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

int n, m;
vi a, b;
int solve(){
    int oddsA = 0;
    int oddsB = 0;
    int evensA = 0;
    int evensB = 0;
    int sumA = accumulate(all(a), 0);
    int sumB = accumulate(all(b), 0);
    if( sumA%2 ==0 && sumB%2 == 0) return 0; 
    for( auto x: a ){
        if( x&1 ){
            oddsA++;
        }
        else evensA++;
    }
    for( auto x: b ){
        if( x&1 ){
            oddsB++;
        }
        else evensB++;
    }
    if( sumA%2 ==1 && sumB%2 == 1 ){
        if( oddsA > 0 && evensB > 0 ) return 1;
        if( oddsB > 0 && evensA > 0 ) return 1;
        return -1;
    }
    if( oddsA > 1 && evensB > 1 ) return 2;
    if( oddsB > 1 && evensA > 1 ) return 2;
    return -1;

}

int TC;
int main()
{
    // file_i_o();
    cin >> n;
    a.resize(n);
    for(auto &x: a) cin >> x;
    cin >> m;
    b.resize(m);
    for(auto &x: b) cin >> x;
    cout << solve();
    return 0;
}


