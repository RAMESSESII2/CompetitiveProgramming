#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long int

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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        int m, n;
        cin >> n >> m;
        int grid[102][102];
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                cin >> grid[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 1));
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                if( grid[i][j] == 0 ){
                    for( int k = 0; k < m; k++){ ans[i][k] = 0; }
                    for( int k = 0; k < n; k++){ ans[k][j] = 0; }
                }
            }
        }
        vector<int> row(n,0 ), col(m, 0);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                if( ans[i][j] == 1 ){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        bool pos = true;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                if( row[i] == 1 or col[j] == 1 ){
                    if( grid[i][j] == 0 ){
                        pos = false;
                        break;
                    }
                }
                if( row[i] == 0 and col[j] == 0 ){
                    if( grid[i][j] == 1 ){
                        pos = false;
                        break;
                    }
                }
            }
        }
        if( !pos ){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


