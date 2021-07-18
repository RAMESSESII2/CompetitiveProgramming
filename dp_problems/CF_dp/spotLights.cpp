#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
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

int n, m;
vector<vector<int> > stage;
ll ans;


int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n >> m;
        stage.resize(n+2);
        for( int i = 1 ; i <= n; i++ ){
            stage[i].resize(m+2, 0);
            for( int j = 1; j <= m; j++ ){
                cin >> stage[i][j];
            }
        }
        for( int i = 1 ; i <= n; i++ ){
            int cur = 0;
            for( int j = 1; j <= m; j++ ){
                cur = cur||stage[i][j];
                if( stage[i][j] == 1 ) continue;
                ans += cur;
            }
        }
        for( int i = 1 ; i <= m; i++ ){
            int cur = 0;
            for( int j = 1; j <= n; j++ ){
                cur = cur||stage[j][i];
                if( stage[j][i] == 1 ) continue;
                ans += cur;
            }
        }
        for( int i = n ; i >= 1; i-- ){
            int cur = 0;
            for( int j = m; j >= 1; j-- ){
                cur = cur||stage[i][j];
                if( stage[i][j] == 1 ) continue;
                ans += cur;
            }
        }
        for( int i = m ; i >= 1; i-- ){
            int cur = 0;
            for( int j = n; j >= 1; j-- ){
                cur = cur||stage[j][i];
                if( stage[j][i] == 1 ) continue;
                ans += cur;
            }
        }
        cout << ans << endl;
    }
    return 0;
}


