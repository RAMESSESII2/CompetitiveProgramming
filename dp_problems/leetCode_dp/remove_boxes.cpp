#include<bits/stdc++.h>
#include <type_traits>
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
int dp[105][105][105];

int recur(vector<int> &boxes, int i , int j , int k){
    if( i > j ) return 0;
    if( dp[i][j][k] != 0 ) return dp[i][j][k];
    int res = (k+1)*(k+1) + recur(boxes,i+1, j, 0);
    for( int r = i+1; r <= j; r++ ){
        if(boxes[i] == boxes[r]){
            res = max(res, recur(boxes, i+1, r-1, 0) + recur(boxes, r, j, k+1));
        }
    }
    return res;
}

int removeBoxes(vector<int> &boxes){
    memset(dp, 0, sizeof dp);
    int n= (int)boxes.size();
    return recur(boxes, 0, n-1, 0);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        vi boxes(n);
        for(auto &x: boxes) cin >> x;
        cout << removeBoxes(boxes);
    }
    return 0;
}


