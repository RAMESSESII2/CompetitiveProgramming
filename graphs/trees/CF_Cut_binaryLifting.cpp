//===============Template==================
#include <atomic>
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

const int N = 100007;
const int K = 20;
int tests;
int n, q;
vector<int> primes[N];
void calc(){
    for( int i = 2; i < N; i++){
        if( primes[i].empty() ){
            for( int y = i; y < N; y += i){
                primes[y].push_back(i);
            }
        }
    }
}
void minimize(int &x, int y){
    if( x > y ) x = y;
}
            
void run_case(){
    cin >> n >> q;
    calc();
    vi a(n);
    for( auto &x: a ) cin >> x;
    vi last(N, n);
    vvi anc(K, vi(n+1, n));
    for( int i = n-1; ~i; --i ){
        minimize(anc[0][i], anc[0][i+1]);
        for( int p : primes[a[i]] ){
            minimize(anc[0][i], last[p]);
            last[p] = i;
        }
    }
    for( int k = 1; k < K; k++ ){
        for( int i = 0; i <= n; i++){
            anc[k][i] =anc[k-1][ anc[k-1][i] ];
        }
    }
    while( q-- ){
        int l, r;
        cin >> l >> r;
        l--, r--;
        int answer = 1; 
        for( int k = K-1; ~k; --k){
            if( anc[k][l] <= r ){
                l = anc[k][l];
                cerr << (1<<k) << endl;
                answer += (1<<k);
            }
        }
        cout << answer << endl;
        cerr << endl;
    }
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

