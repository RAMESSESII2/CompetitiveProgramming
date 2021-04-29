//===============Template==================
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <stdexcept>
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
const int MAX = 1000007;
int tests;
int n;
ll a, b;
int dp[20][180][2];
vi digitsA;
vi digitsB;

vi process(ll a){
    vi d;
    while(a){
        d.push_back(a%10);
        a /= 10;
    }
    return d;
}

ll digitSum(int idx, ll sum, int tight, vi &digit){
    if( idx == -1 ) return sum;
    if( dp[idx][sum][tight] != -1 && tight != 1 ){
        return dp[idx][sum][tight];
    }
    ll ret = 0;
    int k = (tight)? digit[idx]: 9;
    for( int i = 0; i <= k; i++){
        int newtight = (digit[idx] == i)? tight: 0;
        ret += digitSum(idx-1, sum+i, newtight, digit);
    }
    if( !tight )dp[idx][sum][tight] = ret;
    return ret;
}


ll rangeDigitSum(ll a, ll b){
    memset(dp, -1, sizeof dp);
    ll ans1 = digitSum(sz(digitsA)-1, 0, 1, digitsA);
    ll ans2 = digitSum(sz(digitsB)-1, 0, 1, digitsB);
    return ans2-ans1;
}
            
void run_case(){
    cin >> a >> b;
    digitsA = process(a-1);
    digitsB = process(b);
    print(digitsA, sz(digitsA));
    print(digitsB, sz(digitsB));
    cout << rangeDigitSum(a, b) << endl;
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

