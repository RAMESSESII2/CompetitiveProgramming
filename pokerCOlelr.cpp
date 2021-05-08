//===============Template==================
#include <bits/stdc++.h>
#include <valarray>
using namespace std;
#define endl            '\n' 
#define ll              long long int
#define ld              long double
#define pb              push_back
#define ff              first
#define ss              second
#define infl             1e18
#define inf              1e9
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)
#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()
#define print(dp, n); \
    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 
#define countsetbits(i)\
    __builtin_popcount(i)
typedef pair< ll,ll > pll;
typedef pair< int, int> pii;
typedef pair< double, double> pdd;
typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< string > vs;
typedef vector< double > vd;
typedef vector< vi > vvi;
typedef vector< vl > vvl;
const string YES = "YES\n";
const string NO = "NO\n";
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

const int modd = 1000000007;
const int MAX = 2007;
int tests;
int n;
ll dp[MAX][MAX];
vl values;
vl c;

// ll recurse(int pos, int k){
//     // if( k == 0 ) return 0;
//     if( pos != 1 && k <= 0 ) return -1;
//     if( pos <= 0 || k < 0 ) return -1;
//     if( pos == 1 && k < 0) return -1;
//     if( pos == 1 ){
//         return dp[pos][k] = values[pos];
//     }
//     if( dp[pos][k] != -1) return dp[pos][k];
//     dp[pos][k] = 0;
//     for( int i = 1; i <= c[pos]; i++ ){
//         if( pos- i < 0) break;
//         dp[pos][k] = max(dp[pos][k], values[pos] +recurse(pos-i, k-1));
//     }
//     dp[pos][k] = max(dp[pos][k], recurse(pos-1,k));
//     return dp[pos][k];
// }
            
ll recurse(int pos, int k){
    if( pos > n ) return 0;
    if( k < 0) return 0;
    if( dp[pos][k] != -1 ) return dp[pos][k];
    dp[pos][k] = 0;
    for(int i = 1; i <= n; i++){
        // if( pos +i > n) break;
        if( pos + i - c[pos+i] <= pos ){
            dp[pos][k] = max(dp[pos][k], values[pos] + recurse( pos+i, k-1 ));
        }
    }
    return dp[pos][k];
}

void run_case(){
    int K;
    cin >> n >> K;
    values.resize(n+1);
    c.resize(n+1);
    loop(i, 0, n) cin >> values[i+1];
    loop(i, 0, n) cin >> c[i+1];
    memset(dp, -1, sizeof dp);
    cout << recurse(1, K) << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    tests = 1;
    for(int it = 1; it <= tests; it++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

