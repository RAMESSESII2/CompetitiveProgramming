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
//if m == 0 || n == 0, then 1
//if (m < n ) then 0
//

const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n, m;
        cin >> n >> m;
        // if( n == 0 ) {
        //     cout << m+1 << endl;
        // }
        // else if( m == 0 || m < n){
        //     cout << 0 << endl;
        // }
        // else if ( m == n ){
        //     cout << 1 << endl;
        // }
        // else{
            ++m;
            int k = 0;
            for( int i = 31; i >= 0; i--){
                if( ((n&(1<<i))^(m&(1<<i))) == 0){
                    continue;
                }
                if( n&(1<<i)) break;
                if( (m&(1<<i)) ){
                    k |= (1<<i);
                    // n |= (1<<i);
                }
                // else break;
            }
            cout << k << endl;
        // }
    }
    return 0;
}


