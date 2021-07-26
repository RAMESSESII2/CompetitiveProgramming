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
int m, s;
string sans;
int dp[110][1000];

int largestDigits(int ind, int sum){
    if( ind > m ) return inf;
    if(sum > s) return inf;
    if( ind == m && sum == s ) return 0;

    if( dp[ind][sum] != -1 ) return dp[ind][sum];
    int ans = inf;
    for( int i = 9; i >= 0; i--){
        int next = largestDigits(ind+1, sum+i);
        dp[ind][sum] = next;
        if(ans > next){
            sans += to_string(i);
            return 0;
        }
    }
    return inf;
}

int smallesetDiggits(int ind, int sum){
    if( ind > m ) return inf;
    if(sum > s) return inf;
    if( ind == m && sum == s ) return 0;
    if( dp[ind][sum] != -1 ) return dp[ind][sum];
    int ans = inf;
    for( int i = 0; i <= 9; i++){
        int next = smallesetDiggits(ind+1, sum+i);
        dp[ind][sum] = next;
        if(ans > next){
            sans += to_string(i);
            return 0;
        }
    }
    return inf;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> m >> s;
        if( m == 1 && s== 0 ){
            cout << 0 << " " << 0 << endl;
            continue;
        }
        if( s == 0  ){
            cout << -1<< " " << -1 << endl;;
            continue;
        }
        memset(dp, -1, sizeof dp);
        sans = "";
        int a = inf;
        for( int i = 1; i <= 9; i++ ){
            a = smallesetDiggits(1, i);
            if( a == 0 ){
                sans += to_string(i);
                break;
            }
        }
        if( a == inf ) {
            cout << -1<< " " << -1 << endl;;
            continue;
        }
        reverse(sans.begin(), sans.end());
        cout << sans << " ";
        sans = "";
        memset(dp, -1, sizeof dp);
        for( int i = 9; i >= 1; i-- ){
            int a = largestDigits(1, i);
            if( a == 0 ){
                sans += to_string(i);
                break;
            }
        }
        reverse(sans.begin(), sans.end());
        cout << sans << "\n";
    }
    return 0;
}


