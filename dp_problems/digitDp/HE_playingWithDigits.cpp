//===============Template==================
#include <bits/stdc++.h>
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
//sieve of eratosthenes 
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
const int P_MAX = int(1e3) + 5;
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

const int modd = 1000000007;
const int MAX = 1000007;
int tests;
int n;
ll a, b, k;
vi digA, digB;
int dp[18][500][2];
ll ans;

vi getDig(ll x){
    vi dig;
    while( x ){
        dig.push_back(x%10);
        x /= 10;
    }
    return dig;
}

ll getInt(int ind, ll sum, int tight, vi &dig){
    if( ind == -1) return sum;
    if( dp[ind][sum][tight] != -1 && tight != 1 ){
        return dp[ind][sum][tight];
    }
    ll ret = 0L;
    int k = (tight)? dig[ind]: 9;
    for( int i = 0; i <= k; i++){
        ll newtight = (i == dig[ind]) ? tight: 0;
        ret += getInt(ind-1, sum+i, newtight, dig);
        if( prime[ret] && (ret%k)==0 )ans++;
    }
    if( !tight )dp[ind][sum][tight] = ret;
    return ret;
}
            
void run_case(){
    cin >> a >> b >> k;
    digA = getDig(a-1);
    digB = getDig(b);
    memset(dp, -1, sizeof dp);
    ll a;
    ll ans1, ans2;
    ans = 0;
    ans1 = getInt(sz(digA)-1, 0, 1, digA);
    a = ans;
    cerr << ans << endl;
    ans = 0;
    ans2 = getInt(sz(digB)-1, 0, 1, digB);
    cout << ans2 - ans1 << endl;
    cout << ans+a << endl;
}

int main(){
    clock_t begin = clock();
    sieve(P_MAX);
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

