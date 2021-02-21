//====================Template==================
#include <bits/stdc++.h>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;

#define endl            '\n' 
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define ff              first
#define ss              second
#define inf             1e18
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

#define print(dp, n); \
    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 
#define print2(dp, a, n, b, m); \
    loop(i, a, n){loop(j, b, m){cerr << dp[i][j] << " ";}cerr << endl;} 
#define countetbits(i)\
    __builtin_popcount(i)

typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< string > vs;
typedef vector< double > vd;

typedef vector< vi > vvi;
typedef vector< vl > vvl;

typedef pair< ll,ll > pll;
typedef pair< int, int> pii;

//sieve of eratosthenes 
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
const int P_MAX = int(1e5) + 5;
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

// __gcd(m, n)
ll gcd(ll a, ll b)
{
    while (true)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}
ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b)
{
    return (a < b) ? a : b;
}
//Type Inference refers to automatic deduction of the data type of an expression in a programming language.
//Auto lets you declare a variable with particular type whereas decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the type of passed expression.

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

//===========================Template Ends==================================

ll modd = 1000000009;
int n, m, x, y;
int dp[2][1009];
vector<vector<char>> grid;
vector<pair<int, int> > prefix;
vector<pair<int, int> > colCount;
            
void run_case(){
    cin >> n >> m >> x >> y;
    memset(dp, 100000000, sizeof(dp));
    prefix.resize(m+1);
    colCount.resize(m+1);
    grid.resize(n);
    loop(i, 0, n){
        grid[i].resize(m);
        loop(j, 0, m){
            cin >> grid[i][j];
        }
    }
    loop(j, 1, m+1){
        int count = 0;
        loop(i, 1, n+1){
            if( grid[i-1][j-1] == '.' )count++;
        }
        colCount[j].ff = count;
        colCount[j].ss = n-count;
        prefix[j].ff = count+prefix[j-1].ff;
        prefix[j].ss = n-count + prefix[j-1].ss;
    }
    loop(i, 1, m+1){
        cerr << colCount[i].ff << " " << colCount[i].ss << endl;
        cerr << prefix[i].ff << " " << prefix[i].ss << endl;
    }
    //colCount.ff = stores '.' in the column
    //colCount.ss = stores '#' in the column
    //prefix.ff = stores '.' till the column
    //prefix.ss = stores '#' till the column
    dp[0][0] = 0;
    dp[1][0] = 0;
    loop(j, 1, m+1){
        loop(i, x, y+1){
            if( j-i >= 0 ){
                dp[0][j] = min(dp[1][j-i] - prefix[j-i+1].ff + prefix[j].ff, dp[0][j]);
                dp[1][j] = min(dp[0][j-i] - prefix[j-i+1].ss + prefix[j].ss, dp[1][j]);
            }
        }
    }
    cout << min(dp[0][m], dp[1][m]) << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    int tests = 1;
    // int tests;
    // cin >> tests;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}

//Debug
//1. input for test
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

