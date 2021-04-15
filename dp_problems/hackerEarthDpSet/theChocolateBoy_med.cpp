//===============Template==================
#include <bits/stdc++.h>
#include <vector>
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
const string YES = "YES";
const string NO = "NO";
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

const int modd = 1000000009;
const int MAX = 1009;
int n, m;
int z;
vl sweet;
vl price;
string s;
ll dp[MAX][MAX][2];

ll topay(ll sw, ll ind, ll usd){
    if( sw < 0 ) return -infl;
    if( ind < 0 ) return 0L;
    // if( sw == 0 ) return 0L;
    if( dp[sw][ind][usd] != -1 ) return dp[sw][ind][usd];
    if( !usd ){
        dp[sw][ind][usd] = max({topay(sw-sweet[ind]/2, ind-1, 1) + price[ind], topay(sw, ind-1, usd), topay(sw-sweet[ind], ind-1, usd)+price[ind] });
    }
    else{
        dp[sw][ind][usd] = max({ topay(sw-sweet[ind], ind-1, usd) + price[ind],  topay(sw, ind-1, usd)});
    }
    return dp[sw][ind][usd];

}

void run_case(){
    cin >> n >> m;
    ll sw, pr;
    char ty;
    loop(i, 0, n){
        cin >> s >>ty >> sw >> pr;
        if (ty == 'H') continue;
        sweet.pb(sw);
        price.pb(pr);
    }
    z = sz(price);
    loop(i, 0, MAX-1){
        loop(j, 0, MAX-1){
            loop(k, 0, 2){
                dp[i][j][k] = -1;
            }
        }
    }
    ll ans = topay( m, z-1, false );
    cout << ans << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    int tests = 1;
    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

