//===============Template==================
#include <bits/stdc++.h>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
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
// lexical_cast() converts a int into string 
//   string stri = boost::lexical_cast<string>(i_val);  
//=================Template Ends=====================

const int modd = 1000000007;
int tests;
int n, m;
int l, r;
vi arr;
ll ncr[3009][3009];
void comb(){
    loop(i, 0, 3009){
        ncr[i][0] = 1;
        loop(j, 0, i+1){
            if ( i< j) continue;
            if( i == j) ncr[i][j] = 1;
            else if ( i == 0  ) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j-1]%modd + ncr[i-1][j]%modd)%modd;
        }
    }
}

ll binpow(int a, int b ){
    a %= modd;
    ll ans = 1L;
    while( b > 0 ){
        if(b&1) ans = ans * a % modd;
        a = a*a %modd;
        b >>= 1;
    }
    return ans; 
}

void run_case(){
    cin >> n;
    arr.resize(n);
    for( auto &x : arr ) cin >> x;
    //for odd length subsequence 
    ll ans = binpow(2, n-1) % modd;
    // cerr << ans << endl;
    //for even length subsequence
    loop(i, 0, n){
        loop(j, i+1, n){
            if( arr[i] == arr[j] ){
                l = i;
                r = n-1-j;
                ans =(ans%modd+ ncr[l+r][l]%modd)%modd;
                // cerr << ncr[l+r][l];
                ans %= modd;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    // int tests = 1;
    cin >> tests;
    comb();
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

