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
 
int n, m;
vector<int> parent;
vector<int> rankk;
 
// void makeSet(int v){
// }
 
int findSet(int v){
    return parent[v] = (parent[v] == v ? v : findSet(parent[v]));
}
 
void union_(int a, int b){
    int x = findSet(a);
    int y = findSet(b);
    if( rankk[x] == rankk[y] ){
        rankk[x]++;
    }
    if( rankk[x] > rankk[y]  ){
        parent[y] = x;
    }
    else parent[x] = y;
}
            
void run_case(){
    cin >> n >> m;
    parent.resize(n+1);
    rankk.resize(n+1);
    for( int i = 1; i <=n; i++ ){
        parent[i] = i;
        rankk[i] = 1;
        // makeSet(i);
    }
    loop(i, 0, m){
        string s;
        int u, v;
        cin >> s >> u >> v;
        if( s == "union" ){
            if( findSet(u) == findSet(v)) continue;
            union_(u, v);
        }
        else cout << (findSet(v) == findSet(u) ? "YES\n": "NO\n");
    }
    // loop(i, 1, n+1){
    //     cerr << parent[i] << " " << rankk[i] << " \n";
    // }
}
 
int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    // file_i_o();
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
//4. if TLE, remove "cerr"