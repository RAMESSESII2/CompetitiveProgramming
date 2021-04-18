////===============Template==================
//#include <algorithm>
//#include <bits/stdc++.h>
//#include <queue>
//#include <regex>
//#include <vector>
//// #include <boost/lexical_cast.hpp> // for lexical_cast() 
//using namespace std;
//#define endl            '\n' 
//#define ll              long long int
//#define ld              long double
//#define pb              push_back
//#define ff              first
//#define ss              second
//#define infl             1e18
//#define inf              1e9
//#define mid(l, r)       (l+(r-l)/2)
//#define loop(i, a, b)   for(int i=(a); i<b; i++)
//#define loopr(i, a, b)  for(int i=(a); i>b; i--)
//#define sz(a)           int((a).size())
//#define all(c)          c.begin(), c.end()
//#define allr(c)         c.rbegin(), c.rend()
//#define print(dp, n); \
//    loop(i, 0, n){cerr << dp[i] << " ";}cerr << endl; 
//#define printPair(pr, n); \
//    loop(i, 0, n){cerr << pr[i].ff << " " << pr[i].ss << " ";}cerr << endl; 
//#define countsetbits(i)\
//    __builtin_popcount(i)
//typedef pair< ll,ll > pll;
//typedef pair< int, int> pii;
//typedef pair< double, double> pdd;
//typedef vector< long long int > vl;
//typedef vector< int > vi;
//typedef vector< pii > vpii;
//typedef vector< pll > vpll;
//typedef vector< string > vs;
//typedef vector< double > vd;
//typedef vector< vi > vvi;
//typedef vector< vl > vvl;
//const string YES = "YES";
//const string NO = "NO";

////sieve of eratosthenes 
//vector<int> smallest_factor;
//vector<bool> prime;
//vector<int> primes;
//const int P_MAX = int(1e5) + 5;
//void sieve(int maximum) {
//    maximum = max(maximum, 1);
//    smallest_factor.assign(maximum + 1, 0);
//    prime.assign(maximum + 1, true);
//    prime[0] = prime[1] = false;
//    primes = {};
//    for (int p = 2; p <= maximum; p++)
//        if (prime[p]) {
//            smallest_factor[p] = p;
//            primes.push_back(p);
//            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
//                if (prime[i]) {
//                    prime[i] = false;
//                    smallest_factor[i] = p;
//                }
//        }
//}
//long long binpow(long long a, long long b, long long m) {
//    a %= m;
//    long long res = 1;
//    while (b > 0) {
//        if (b & 1)
//            res = res * a % m;
//        a = a * a % m;
//        b >>= 1;
//    }
//    return res;
//}
//// __gcd(m, n)
//ll gcd(ll a, ll b)
//{
//    while (true)
//    {
//        if (a == 0) return b;
//        b %= a;
//        if (b == 0) return a;
//        a %= b;
//    }
//}
//ll lcm(ll a, ll b)
//{
//    ll temp = gcd(a, b);

//    return temp ? (a / temp * b) : 0;
//}
//// Returns first i in [l, r] s.t. predicate(i) is true. Never evaluates r.
//template <typename I, typename P> I binarysearch(const P &predicate, I l, I r) {
//    l--;
//    while (r - l > 1) {
//        auto mid = l + (r - l) / 2;
//        if (predicate(mid))
//            r = mid;
//        else
//            l = mid;
//    }
//    return r;
//}
////MST template
//struct Edge{
//    int from, to, weight, index;
//    bool del;
//    Edge(int f, int t, int w, int idx){ 
//        from = f;
//        to = t;
//        weight = w;
//        index = idx;
//        del = false;
//    }
//    bool operator <(const Edge& e)const{
//        return weight > e.weight;
//    }
//    bool operator ==(const Edge& e)const{ 
//        return ( from == e.from && to == e.to && weight == e.weight );
//    }
//};
////disjoint set union template
//struct DisjointSet{
//    vi ranks;
//    vi parent;
//    DisjointSet(int n){
//        ranks.resize(n, 0);
//        parent.resize(n);
//        for( int i = 0; i < n; i++) parent[i] = i;
//    }
//    int findSet(int v){
//        return parent[v] = ((parent[v] == v)? v: findSet(parent[v]));
//    }
//    bool unionSet(int u, int v){
//        int x = findSet(u);
//        int y = findSet(v);
//        if( x == y ) return false;
//        if( ranks[x] == ranks[y] ) ranks[x]++;
//        if( ranks[x] > ranks[y] ){
//            parent[y] = x;
//        }
//        else parent[x] = y;
//        return true;
//    }
//};
////function to get the MST, its cost and edges included
//pair<int, vector < Edge > > getMST(int n, vector< Edge > edges){
//    int cost = 0;
//    priority_queue< Edge > q;
//    vector < Edge > res;

//    DisjointSet djSet(n);
//    for( int i = 0; i < edges.size(); i++ ){
//        if( !edges[i].del )q.push(edges[i]);
//    }
//    while( !q.empty() ){ 
//        Edge curE = q.top();
//        q.pop();
//        if( djSet.unionSet(curE.from, curE.to) ){ 
//            cost += curE.weight;
//            res.push_back(curE);
//        }
//    }
//    if( res.size() != n-1 ) return make_pair(inf, vector< Edge >());
//    return make_pair(cost, res);
//}
//template <class A, class B>
//auto findMin(A a, B b) -> decltype(a < b ? a : b)
//{
//    return (a < b) ? a : b;
//}
////Type Inference refers to automatic deduction of the data type of an expression in a programming language.
////Auto lets you declare a variable with particular type whereas decltype lets you extract the type from the variable so decltype is sort of an operator that evaluates the type of passed expression.
//void file_i_o(){
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    freopen("cerr.txt", "w", stderr);
//#endif
//}
//// lexical_cast() converts a int into string 
////   string stri = boost::lexical_cast<string>(i_val);  
////=================Template Ends=====================

//const int modd = 1000000009;
//const int MAX = 1000007;
//int tests;
//int n, m, k;

//struct Edges{
//    int from, to;
//    ll wt;
//    vi cs;
//    bool dl;
//    Edges(int f, int t, ll w, vi c){
//        from = f;
//        to = t;
//        wt = w;
//        cs = c;
//        dl = false;
//    }
//    bool operator < (const Edges &e)const {
//        return wt > e.wt;
//    }
//    bool operator == (const Edges &e)const {
//        return (wt == e.wt && from == e.from && to == e.to);
//    }
//};

//struct Disj{
//    vector<int> rk;
//    vector<int> parent;
//    Disj(int n){
//        rk.resize(n+1);
//        parent.resize(n+1);
//        for( int i = 1; i <= n; i++ ){
//            rk[i] = 1;
//            parent[i] = i;
//        }
//    }
//    int findSet(int x){
//        while( parent[x] != x ){
//            x = parent[x];
//        }
//        return x;
//        // return parent[x] = (parent[x] == x)? x: findSet(parent[x]);
//    }
//    bool unionSet(int x, int y){
//        x = findSet(x);
//        y = findSet(y);
//        if( x == y ) return false;
//        if( rk[x] == rk[y] ) rk[x]++;
//        if( rk[x] > rk[y] )parent[y] = x;
//        else parent[x] = y;
//        return true;
//    }
//};

//set<int> findMst(int n, vector<Edges> edge){
//    priority_queue< Edges > q;
//    Disj dj(n);
//    for( int i = 0; i < sz(edge); i++ ){
//        q.push(edge[i]);
//    }
//    set<int> ans;
//    while( !q.empty() ){
//        Edges e = q.top();
//        q.pop();
//        if( dj.unionSet(e.from , e.to) ){
//        cerr << e.from << " " << e.to  << "  " << e.wt << endl;
//            loop(i, 0, sz(e.cs)){
//                ans.insert(e.cs[i]);
//            }
//        }
//    }
//    return ans;
//}

//vl c;
//vector<Edges> ed;

//int main(){
//    clock_t begin = clock();
//    // sieve(P_MAX);
//    file_i_o();
//    cin >> n >> m >> k;
//    c.resize(k+1);
//    // ed.resize(m);
//    loop(i, 1, k+1) cin >> c[i];
//    int x, y, l;
//    ll ans;
//    vi temp;
//    loop(i, 0, m){
//        cin >> x >> y >> l;
//        temp.resize(l);
//        ans = 0L;
//        loop(j, 0, l){
//            cin >> temp[j];
//            ans += c[temp[j]];
//        }
//        Edges e{x, y, ans, temp};
//        ed.push_back(e);
//    }
//    sort(all(ed));
//    set<int> st;
//    st = findMst(n, ed);
//    ans = 0L;
//    for( auto x: st ){
//        ans += c[x];
//    }
//    cout << ans << endl;

//    #ifndef ONLINE_JUDGE
//    clock_t end = clock();
//        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
//    #endif
//    return 0;
//}
////Debug
////1. size of vi and other containers if applicable
////2. look for type conversion, char to int
////3. look for declaration of large arrays.
//
#include <bits/stdc++.h>
using namespace std;
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


#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;

ll c[N];
vector<pair<int, ll> > con[N];
int sz = 0;
int vis[N];
ll ans = 0;
ll ans2 = 0;
// Equivalent problem : Find the spanning tree with minimum
// bitwise OR of edges.
// Check if we can get a connected graph using edges 
// which don't require ith token

void dfs(int s, ll i){
	sz++;
	vis[s] = 1;
	for(auto it : con[s]){
		int v = it.first;
		ll cost = it.second;
		if((cost & i) != cost) continue;
		if(!vis[v]) dfs(v, i);
	}
}

void dfs2(int s){
	vis[s] = 1; sz++;
	for(auto v : con[s]){
		if(!vis[v.first]) dfs2(v.first);
	}
}
int main(){

   file_i_o();
	int n, m, k, u, v, l, ind;
    cin >> n >> m >> k;

	for(int i = 0; i < k; i++){
		cin >> c[i];
		if(i) assert(c[i] >= 2 * c[i - 1]);
	}
	for(int i = 1; i <= m; i++){
        cin >> u >> v >> l;
        ll cost = 0;
		for(int j = 1; j <= l; j++){
            cin >> ind;
			cost |= (1LL << (ind - 1));
            cerr << (1LL << (ind - 1)) << " " << cost << endl;
		}
		con[u].push_back({v, cost});
		con[v].push_back({u, cost});
	}
	dfs2(1);
	if(sz != n){
		cout << -1;
		return 0;
	}
	ll ans = 0, X = ((1LL << k) - 1), ret = 0;
	for(int i = k - 1; i >= 0; i--){
		sz = 0; memset(vis, 0, sizeof vis);
		dfs(1, X ^ (1LL << i));
		if(sz != n){
			ans |= (1LL << i);
			ret += c[i];
		}
		else X ^= (1LL << i);
	}

    cout << ret << endl;

}
