//===============Template==================
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <numeric>
#include <regex>
#include <set>
#include <type_traits>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
using namespace std;
#define endl            '\n' 
typedef long long int ll;
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
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
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
// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
template <typename I, typename P> I binarysearch(const P &predicate, I l, I r) {
    l--;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if (predicate(mid))
            r = mid;
        else
            l = mid;
    }
    return r;
}
//MST template
struct Edge{
    int from, to, weight, index;
    bool del;
    Edge(int f, int t, int w, int idx){ 
        from = f;
        to = t;
        weight = w;
        index = idx;
        del = false;
    }
    bool operator <(const Edge& e)const{
        return weight > e.weight;
    }
    bool operator ==(const Edge& e)const{ 
        return ( from == e.from && to == e.to && weight == e.weight );
    }
};
//disjoint set union template
struct DisjointSet{
    vi ranks;
    vi parent;
    DisjointSet(int n){
        ranks.resize(n, 0);
        parent.resize(n);
        for( int i = 0; i < n; i++) parent[i] = i;
    }
    int findSet(int v){
        return parent[v] = ((parent[v] == v)? v: findSet(parent[v]));
    }
    bool unionSet(int u, int v){
        int x = findSet(u);
        int y = findSet(v);
        if( x == y ) return false;
        if( ranks[x] == ranks[y] ) ranks[x]++;
        if( ranks[x] > ranks[y] ){
            parent[y] = x;
        }
        else parent[x] = y;
        return true;
    }
};
//function to get the MST, its cost and edges included
pair<int, vector < Edge > > getMST(int n, vector< Edge > edges){
    int cost = 0;
    priority_queue< Edge > q;
    vector < Edge > res;

    DisjointSet djSet(n);
    for( int i = 0; i < edges.size(); i++ ){
        if( !edges[i].del )q.push(edges[i]);
    }
    while( !q.empty() ){ 
        Edge curE = q.top();
        q.pop();
        if( djSet.unionSet(curE.from, curE.to) ){ 
            cost += curE.weight;
            res.push_back(curE);
        }
    }
    if( res.size() != n-1 ) return make_pair(inf, vector< Edge >());
    return make_pair(cost, res);
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
//=================Template Ends=====================

const int modd = 1000000009;
const int MAX = 200007;
int tests;
int n, m;
int x, y;

struct DSU{
    int parent[MAX], rankk[MAX];
    DSU(int n){
        loop(i, 1, n+1){ 
            parent[i] = i; 
            rankk[i] = 1; 
        }
    }
    int findSet(int v){
        return parent[v] = (parent[v] == v) ? v : findSet(parent[v]);
    }
    bool unionSet(int a, int b){
        a = findSet(a); b = findSet(b);
        if( a == b ) return false;
        rankk[a] += rankk[b];
        parent[b] = a;
        // rankk[b] = 0;
        return true;
    }
};

void run_case(){
    cin >> n >> m;
    DSU dj(n);
    loop(i, 0, m){
        cin >> x >> y;
        dj.unionSet(x, y);
    }
    ll ans = 0L;
    ans = n * ll(n-1L);
    //initially ans = all the ways of doing it
    loop(i, 1, n+1){
        if( dj.parent[i] == i ){
            // ms.insert(dj.rankk[i]);
            ans -= (dj.rankk[i]* ll(dj.rankk[i]-1L));
        }
    }
    cout << ans << endl;
    // for( auto x : ms ) cerr << x << " " ;
    // cerr << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    // int tests = 1;
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

