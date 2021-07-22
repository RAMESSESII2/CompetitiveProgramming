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
int t[50009][6];

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int m, n;
        cin >> m >> n;
        memset(t, 0, sizeof t);
        for( int i = 1; i <= m; i++ ){
            for( int j = 1; j <= n; j++){
                cin >> t[i][j];
            }
        }
        for( int j = 1; j <= m; j++ ){
            t[j][1] += t[j-1][1];
        }
        for( int i = 2; i <= n; i++ ){
            for( int j = 1; j <= m; j++){
                if( t[j-1][i] >= t[j][i-1] ){
                    t[j][i] += t[j-1][i];
                }
                else{
                    t[j][i] += t[j][i-1];
                }
            }
        }
        for( int j = 1; j <= m; j++){
            cout << t[j][n] << " ";
        }
    }
    return 0;
}


