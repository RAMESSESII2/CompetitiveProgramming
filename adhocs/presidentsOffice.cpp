//====================Template==================
#include <bits/stdc++.h>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define endl            '\n' 
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
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl; 
#define print2(dp, a, n, b, m); \
    loop(i, a, n){loop(j, b, m){cout << dp[i][j] << " ";}cout << endl;} 
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
ll n, m;
char presColor;
ll dp[100005];
            
void run_case(){
    cin >> n >> m >> presColor;
    vector< vector <char> > matrix(n, vector< char > (m));
    int pmini = 9878979, pminj = 9878979;
    int pmaxi = -9878979, pmaxj = -9878979;
    loop(i, 0, n){
        loop(j, 0, m){
            cin>> matrix[i][j];
            if( matrix[i][j] == presColor ){
                pmini = min( pmini, i );
                pmaxi = max( pmaxi, i );
                pminj = min( pminj, j );
                pmaxj = max( pmaxj, j );
            }
        }
    }
    cerr << pmini << " " << pmaxi << " " << pmaxj << " " << pminj << endl;
    set< char > ans;
    int i = pmini; int j = 0;
    if( i > 0){
        for( j = pminj; j <= pmaxj; j++  ){
            ans.insert( matrix[i-1][j] );
        }
    }
    i = pmaxi;
    if( i < n-1){
        for( j = pminj; j <= pmaxj; j++  ){
            ans.insert( matrix[i+1][j] );
        }
    }
    j = pminj;
    if( j > 0){
        for( i = pmini; i <= pmaxi; i++){
            ans.insert( matrix[i][j-1] );
        }
    }
    j = pmaxj;
    if( j < m-1){
        for( i = pmini; i <= pmaxi; i++){
            ans.insert( matrix[i][j+1] );
        }
    }
    ans.erase('.');
    ans.erase(presColor);
    // tr( ans, it ){ cout << *it << " ";}
    cout << sz(ans) << endl;
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


