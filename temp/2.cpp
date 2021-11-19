
#include <algorithm>
#include<bits/stdc++.h>
#include <sched.h>
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
    sort(all(a));
    sort(all(b));
    int minLoadSoFar = n/m;
    int soFar = 0;
    for(int i = 0; i < m; i++){
        int minLoad = lower_bound(all(a), b[i])-a.begin();
        minLoad++;
        if( i == 0 ) soFar = minLoad;
        else {
            int t = minLoad;
            minLoad -= soFar;
            soFar = t;
        }
        if( minLoad < minLoadSoFar ){
            minLoadSoFar = minLoad;
        }
        // cerr << minLoadSoFar << " " << minLoad << endl;
    }
    return 2*(n/minLoadSoFar)+(n%minLoadSoFar == 1 ? 1:0);
}

int TC;
int main()
{
    file_i_o();
    cin >> n;
    cin >> m;
    a.resize(n);
    for(auto &x: a) cin >> x;
    b.resize(m);
    for(auto &x: b) cin >> x;
    cout << solve();
    return 0;
}


