#include<bits/stdc++.h>
#include <type_traits>
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

void run(){
        vector<vector<char> > grid(4, vector<char>(4));
        int countx, counto;
        counto = countx = 0;
        for( int i = 1; i <= 3; i++ ){
            for( int j = 1; j <= 3; j++){
                cin >> grid[i][j];
                if( grid[i][j] == 'X' ) grid[i][j] = 'x';
                if( grid[i][j] == 'O' ) grid[i][j] = 'o';
                if( grid[i][j] == 'x')countx++;
                if( grid[i][j] == 'o' ) counto++;
            }
        }
        if( counto > countx || countx-counto > 1 ){
            cout << 3 << endl;
            return;
        }
        bool wonO, wonX;
        wonO = wonX = false;
        for( int i = 1; i <= 3; i++){
            char x = grid[i][1];
            bool what= false;
            for( int j = 2; j <= 3; j++ ){
                if( grid[i][j] != x ) {
                    what = false;
                    break;
                }
                what = true;
            }
            if( what  ){
                if( x == 'o' ){
                    if( wonO ) {
                        cout << 3 <<endl;
                        return;
                    }
                    wonO =true;
                }
                if( x == 'x' ){
                    if( wonX ) {
                        cout << 3 <<endl;
                        return;
                    }
                    wonX =true;
                }
            }
        }
        // cerr << wonO << " " << wonX << endl;
        for( int j = 1; j <=3; j++ ){
            char x = grid[j][1];
            bool what= false;
            for( int i = 1; i <= 3; i++){
                if( grid[i][j] != x ) {
                    what = false;
                    break;
                }
                what = true;
            }
            if( what  ){
                if( x == 'o' ){
                    if( wonO ) {
                        cout << 3 <<endl;
                        return;
                    }
                    wonO =true;
                }
                if( x == 'x' ){
                    if( wonX ) {
                        cout << 3 <<endl;
                        return;
                    }
                    wonX =true;
                }
            }
        }
        // cerr << wonO << " " << wonX << endl;
        if( grid[1][1] == grid[2][2] && grid[3][3] == grid[2][2] ){
            if( grid[1][1] == 'o' ){
                if( wonO ) {
                    cout << 3 <<endl;
                    return;
                }
                wonO =true;
            }
            if( grid[1][1] == 'x' ){
                if( wonX ) {
                    cout << 3 <<endl;
                    return;
                }
                wonX =true;
            }
        }
        // cerr << wonO << " " << wonX << endl;
        if( grid[1][3] == grid[2][2] && grid[3][1] == grid[2][2] ){
            if( grid[1][3] == 'o' ){
                if( wonO ) {
                    cout << 3 <<endl;
                    return;
                }
                wonO =true;
            }
            if( grid[1][3] == 'x' ){
                if( wonX ) {
                    cout << 3 <<endl;
                    return;
                }
                wonX =true;
            }
        }
        // cerr << wonO << " " << wonX << endl;
        if( wonX && wonO ){
            cout << 3 << endl;
            return;
        }
        // cerr << wonO << " " << wonX << endl;
        if( wonO || wonX ){
            if( wonX ){
                if( countx <= counto ){
                    cout << 3 << endl;
                }
                else{
                    cout << 1 << endl;
                }
            }
            else{
                if( countx != counto ){
                    cout << 3 << endl;
                }
                else{
                    cout << 1 << endl;
                }
            }
        }
        else cout << 2 << endl;

}

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        run();
    }
    return 0;
}


