//====================Template==================
#include <bits/stdc++.h>
using namespace std;

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
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl; 
#define print2(dp, a, n, b, m); \
    loop(i, a, n){loop(j, b, m){cout << dp[i][j] << " ";}cout << endl;} 
#define countetbits(i)\
    __builtin_popcount(i)

typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< string > vs;

typedef vector< vi > vvi;
typedef vector< vl > vvl;

typedef pair< ll,ll > pll;
typedef pair< int, int> pii;

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
#endif
}
ll n, m;
vector< vector < pair< ll , ll > > > adjacencyList(10000);
            
void run_case(){
    cin >> n >> m;
    adjacencyList.resize(n+1);
    loop(i, 0, m){
        ll v1, v2, c;
        cin >> v1>>  v2 >> c;
        v1--; v2--;
        adjacencyList[v1].push_back(pll(v2, c));
        adjacencyList[v2].push_back(pll(v1, c));
    }
   // PriorQueue of pll: pair(dist, id  = i * 4 + state) [we are doing a graph transformation from n to 4n nodes]
   // id -> (i, state) = (i, a * 2 + b) -> original node i, skipped an edge a times, doubled an edge b times
    priority_queue<pll, vector<pll>, greater<pll> > pq;
    vl dist(4*n, inf);
    auto push = [&](ll cur, ll state, ll d){ 
        int id = cur*4 + state;
        if(d > dist[id]) return;
        dist[id] = d;
        pq.push(pll(d,id));
    };
    push(0, 0, 0);
    while( !pq.empty() ){ 
        pll p = pq.top();
        pq.pop();
        ll id = p.ss;
        if( p.ff != dist[id] ) continue;

        ll cur = id / 4, a = (id % 4) / 2, b = id % 2;
        for( pll e : adjacencyList[cur] ){
            ll nxt = e.ff;
            for(ll na = 0; na < 2; ++na){
                if( na < a ) continue;
                for ( int nb = 0; nb < 2; ++nb ){ 
                    ll ndist = dist[id] + e.ss;
                    if( na > a ) ndist -= e.ss;
                    if( nb > b ) ndist -= e.ss;
                    push( nxt, na * 2 + nb, ndist );

                }
            }
        }
    }
    vl ans(n);
    for(int i =1; i< n; ++i){
        ans[i] = dist[ i * 4 + 3 ];
    }
    for( int i = 1; i < n; ++i ) cout << ans[i] << " ";
    cout << endl;
    

    /* loop(i, 1, e+1){ */
    /*     loop(j, 0,  sz(adjacencyList[i])){ cout << adjacencyList[i][j].ff << " " << adjacencyList[i][j].ss << endl; */
    /*     } */
    /*     cout << endl; */
    /* } */
}

int main(){
    clock_t begin = clock();
    file_i_o();
    int tests = 1;
    /* int tests; */
    /* cin >> tests; */

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


