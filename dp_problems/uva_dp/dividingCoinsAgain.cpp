#include <algorithm>
#include<bits/stdc++.h>
#include <numeric>
#include <vector>
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
vector<int> arr;
int lim;
int N;
int dp[50001];

int knapsack(int N, int W){
    for( int i = 0; i <= W; i++ ){dp[i] = 0;}
    for( int i = 1; i <= N; i++ ){
        for( int j = W; j > 0; j--){
            if( arr[i-1] <= j) dp[j] = max(dp[j], arr[i-1]+ dp[j-arr[i-1]]);
        }
    }
    return dp[W];
}

int maxCoins(int ind, int lim){
    if( ind >= N ) return 0;
}

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        cin >> N;
        arr.assign(N, 0);
        for( auto &x: arr ) cin >> x;
        int total  = accumulate(arr.begin(), arr.end(), 0);
        lim = total/2;
        // memset(dp, 0, sizeof dp);
        // for( int i = 1; i <= N; i++ ){
        //     for( int c = lim; c > 0; c-- ){
        //         if( c >= arr[i-1] ){
        //             dp[c] = max(dp[c], dp[c-arr[i-1] + arr[i-1]]);
        //         }
        //     }
        // }
        int ans = knapsack(N, lim);
        cout << total-2*ans << endl;
    }
    return 0;
}


