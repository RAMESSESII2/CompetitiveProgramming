/* Given an a×b rectangle, your task is to cut it into squares. On each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers. What is the minimum possible number of moves? */
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define vi              vector<ll>
#define vs              vector<string>
#define pb              push_back
#define pii             pair<ll,ll>

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
bool compare(int a, int b){
    return a>b;
}

int main(){
    file_i_o();
    ll a, b;
    cin >> a >> b;
    vector<vector<ll>> dp(a+1, vector<ll>(b+1, INT_MAX));
    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            if (i==j) dp[i][j] = 0;
            else{
                for(int k=1; k<=i-1; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
                for(int k=1; k<=j-1; k++){
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
            }

        }
    }
    }
    cout << dp[a][b];

}


/* INPUT */
/* 3 4 */
/* OUTPUT */
/* 3 */
