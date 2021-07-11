#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

void file_i_o(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}

const int inf = INT_MAX;
const int maxm = 500;
int dp[maxm][maxm];

int TC;
int main()
{
    file_i_o();
    int t = 1;
    string s1, s2;
    while (getline(cin, s1) && s1[0] != '#')
    {
        getline(cin, s2);
        int n1 = (int)s1.length();
        int n2 = (int)s2.length();
        memset(dp, 0, sizeof dp);
        for( int i = 0; i < n1; i++){
            for( int j = 0; j < n2; j++){
                if( s1[i] == s2[j] ){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }
                else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n",t++,dp[n1][n2]);
    }
    return 0;
}


