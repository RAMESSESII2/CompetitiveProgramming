//===============Template==================
#include <algorithm>
#include <bits/stdc++.h>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;
typedef long long int ll;
typedef long double ld;
#define endl            '\n' 
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
#define printPair(pr, n); \
    loop(i, 0, n){cerr << pr[i].ff << " " << pr[i].ss << " ";}cerr << endl; 
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
// lexical_cast() converts a int into string 
//   string stri = boost::lexical_cast<string>(i_val);  
//=================Template Ends=====================

const int modd = 1000000007;
const int MAX = 1000007;
int tests;
int n, m, k, p;
vi arr;

void run_case(){
    cin >> n >> k >> p;
    arr.resize(n);
    for( auto &x : arr ) cin >> x;
    if( k&1){
        cout << ((p == 0) ? (*max_element(all(arr))): *min_element(all(arr))) << endl;
        return;
    }
    int bestLarg = -inf, bestSmall = inf;
    int curL, curS;
    for( int i =1 ; i < n-1; i++){
        curL = max(arr[i-1], arr[i+1]);
        bestSmall = min(bestSmall, curL);
        curS = min(arr[i-1], arr[i+1]);
        bestLarg = max(bestLarg, curS);
    }
    bestSmall = min( bestSmall, arr[1] );
    bestSmall = min( bestSmall, arr[n-2] );
    bestLarg = max( bestLarg, arr[1] );
    bestLarg = max( bestLarg, arr[n-2] );
    if( n == 2){
        bestLarg = max(arr[0], arr[1]);
        bestSmall = min(arr[0], arr[1]);
    }
    if( p == 0 ) cout << bestLarg << endl;
    else cout << bestSmall << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    tests = 1;
    cin >> tests;

    for( int i = 1; i <= tests; i++ )
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}
//Debug
//1. size of vi and other containers if applicable
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

