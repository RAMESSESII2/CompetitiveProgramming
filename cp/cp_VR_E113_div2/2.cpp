#include<bits/stdc++.h>
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
//given the string of 1s and 2s, let's convert them into 0s and 1s resp.
//eg- 2122 = 1011
//when it's going to be impossible->when the sum is <=2;
//else it's always possible
//let's handle the possible case;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n;
        string s;
        cin >> n >> s;
        int sum = 0;
        for( auto x: s) if( x=='2' ) sum++;
        if( sum == 2 or sum == 1){
            cout << "NO\n";
            continue;
        }
        vector<vector<char>> ans(n, vector<char>(n, '*'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if( i == j ){ 
                    ans[i][j] = 'X';
                    continue;
                }
                if( ans[i][j] != '*' ) continue;
                if( s[i] == '2' && s[j] == '2' ){ 
                    ans[i][j] = '+';
                    ans[j][i] = '-';
                    s[i] = '3';
                }
                else if( s[i] == '1' ){
                    ans[i][j] = '=';
                    ans[j][i] = '=';
                }
                else if( s[i] == '3' ) {
                    ans[i][j] = '-';
                    ans[j][i] = '+';
                }
            }
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}


