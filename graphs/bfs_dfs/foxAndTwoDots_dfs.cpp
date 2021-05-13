#include<bits/stdc++.h>
#include <system_error>
#include <utility>
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
int n, m;
char grid[55][55];
int visited[55][55];
int dirx[4] = {1, -1, 0, 0};
int diry[4] = {0, 0, 1, -1};
bool ans;


bool dfs(char og, int x, int y, int px, int py){
    visited[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int r = dirx[i]+x;
        int c = diry[i]+y;
        if( r <= 0 or c <= 0 or r > n or c > m ) continue;
        if( r == px and c == py) continue;
        if(grid[r][c] != og) continue;
        if( visited[r][c] ) return 1;
        if(dfs(og, r, c, x, y)) return 1;
    }
    return 0;
}

void run(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            cin >> grid[i][j];
        }
    }
    ans =false;
    memset(visited, 0, sizeof visited);
    for(int i = 1; i <= n; i++ ){
        for( int j = 1; j <= m; j++ ){
            if( visited[i][j] == 0 ){
                // cerr << i << " " << j << endl;
                ans = dfs(grid[i][j], i, j, -1, -1);
                if( ans ){
                    cout << "Yes";
                    return;
                }
            }
        }
    }
    cout << "No";
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        run();
    }
    return 0;
}


