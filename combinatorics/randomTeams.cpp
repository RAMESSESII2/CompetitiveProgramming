#include<bits/stdc++.h>
#include <cstdint>
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
        int64_t n, m;
        cin >> n >> m;
        int64_t kmin = 0L, kmax = 0L;
        //finding minm and maxm teams
        if( n == m ){
            cout << 0 << " " << 0 << endl;
            continue;
        }
        //minm teams pairs => equally distribute
        int64_t rem = n%m;
        kmin += (rem*(n/m+1L)*(n/m)/2L);
        kmin += ((m-rem)*(n/m)*(n/m-1L)/2L);
        //maxm team pairs => n-(m-1) in first and rest have one
        kmax = ((n-m+1L)*(n-m)/2L);
        cout << kmin << " " << kmax << endl;
    }
    return 0;
}


