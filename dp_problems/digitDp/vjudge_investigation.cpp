//===============Template==================
#include <bits/stdc++.h>
#include <bits/types/FILE.h>
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
int a, b, k;
int dp[12][90][90][2];
vi num;

int findAns(int pos, int val, int sum, int f){
    if( pos == num.size() ){
        if( sum == 0 and val == 0) return 1;
        return 0;
    }
    int &res = dp[pos][val][sum][f];
    if( res != -1 ) return res;
    res = 0;
    int lmt;
    if( f == 0) lmt = num[pos];
    else lmt = 9;
    for( int dgt = 0; dgt <= lmt; dgt++){
        int nf = f;
        if( f == 0 && dgt < lmt ) nf = 1;
        res += findAns(pos+1, (val*10 + dgt)%k, (sum+dgt)%k, nf);
    }
    return res;
}

int solve(int b){
    num.clear();
    memset(dp, -1, sizeof dp);
    while(b > 0){
        num.pb(b%10);
        b /= 10;
    }
    reverse(all(num));
    return findAns(0, 0, 0, 0);
}
            
int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    cin >> tests;
    for(int it = 1; it <= tests; it++ ){
        cin >> a >> b >> k;
        int ans = 0;
        if( k < 84) ans = solve(b)- solve(a-1);
        cout << "Case " << it << ": " <<  ans << endl;
    }

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

