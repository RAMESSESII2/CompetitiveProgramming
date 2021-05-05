//===============Template==================
#include <bits/stdc++.h>
#include <cstdint>
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

int tests;
int n, m;
vi arr;

struct item{
    int sum, seg, pre, suf;
};
struct segTree{
    int size;
    vector<item> values;

    void init(int n){
        size = 1;
        while( size < n ) size <<= 1;
        values.resize(2*size);
    }

    item neutralItem = {0, 0, 0, 0};
    item single(int v){
        if( v > 0 ){
            return {v, v, v, v};
        }
        else return {v, 0, 0, 0};
    }
    item merge(item a, item b){
        return{
            a.sum+b.sum,
            max({a.seg, b.seg, a.suf+b.pre}),
            max(a.pre, a.sum+b.pre),
            max(b.suf, b.sum+a.suf)
        };
    }

    void build(vector<int> &a){
        build(a, 0, 0, size);
    }
    void build ( vector<int> &a, int x, int lx, int rx ){
        if( rx - lx == 1){
            if( lx < (int)a.size()){
                values[x] = single( a[lx] );
            }
            return;
        }
        int m = lx+(rx-lx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    void sett(int i, int v){
        sett(i, v, 0, 0, size);
    }
    void sett( int i , int v, int x, int lx, int rx ){
        if( rx - lx == 1){
            values[x] = single(v);
            return;
        }
        int m = lx+(rx-lx)/2;
        if( i < m){
            sett(i, v, 2*x+1, lx, m);
        }
        else sett(i, v, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
    item calc(int l, int r, int x, int lx, int rx){
        if( lx >= r || l >= rx ) return neutralItem;
        if( lx >= l && rx <= r) return values[x];
        int m = lx+(rx-lx)/2;
        item s1 = calc(l, r, 2*x+1, lx, m);
        item s2 = calc(l, r, 2*x+2, m, rx);
        return merge(s1, s2);
    }
};

struct SegmentTree{
    int size;
    vector<item> values;

    void init(int n){
        size = 1;
        while( size < n ) size <<= 1;
        values.resize(2*size);
    }

    item neutralItem = {0, 0, 0, 0};
    item single(int v){
        if( v > 0 ){
            return {v, v, v, v};
        }
        else return {v, 0, 0, 0};
    }
    item merge(item a, item b){
        return{
            a.sum+b.sum,
            max({a.seg, b.seg, a.suf+b.pre}),
            max(a.pre, a.sum+b.pre),
            max(b.suf, b.sum+a.suf)
        };
    }

    void build(vector<int> &a){
        return build(a, 0, 0, size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if( rx - lx == 1 ){
            if( lx < (int)a.size() ){
                values[x] = single(a[lx]);
            }
            return;
        }
        int m = lx+(rx-lx)/2;
        build(a, 2*x+1, lx, m);
        build(a, 2*x+2, m, rx);
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }

    void set(int i, int v){
        return set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if( rx-lx == 1 ){
            values[x] = single(v);
            return;
        }
        int m = lx+(rx-lx)/2;
        if( i < m){
            set(i, v, 2*x+1, lx, m);
        }
        else{
            set(i, v, 2*x+2, m, rx);
        }
        values[x] = merge(values[2*x+1], values[2*x+2]);
    }
    item calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }
    item calc(int l, int r, int x, int lx, int rx){
        if( l >= rx || r <= lx ) return neutralItem;
        if( lx >= l && rx <= r ) return values[x];
        int m = lx+(rx-lx)/2;
        item s1 = calc(l, r, 2*x+1, lx, m);
        item s2 = calc(l, r, 2*x+2, m, rx);
        return merge(s1, s2);
    }
};
            
void run_case(){
    cin >> n >> m;
    arr.resize(n);
    for( auto &x: arr) cin >> x;
    segTree seg;
    seg.init(n);
    seg.build(arr);
    cout << seg.calc(0, n).seg << endl;
    int i, v;
    while( m-- ){
        cin >> i >> v;
        seg.sett(i, v);
        cout << seg.calc(0, n).seg << endl;
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

