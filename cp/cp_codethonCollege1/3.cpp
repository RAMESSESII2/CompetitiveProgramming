//===============Template==================
#include <bits/stdc++.h>
#include <string>
// #include <boost/lexical_cast.hpp> // for lexical_cast() 
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

#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

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
const string YES = "YES";
const string NO = "NO";


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
const int MAX = 1000007;
int m, k, p, l;
string n;
ll mod(string num, int a)
{
    ll res = 0;
    for (int i = 0; i < num.length(); i++)
         res = (res*10L+ (int)num[i] - '0') %a;
 
    return res;
}
 
void run_case(){
    cin >> l >> m >> n;
    //{
    //    //brute force
    //    if( l == 1 ) cout << stoi(n) % m << endl;
    //    else{
    //        ll ans = -inf;
    //        for( int i = 0; i < l; i++ ){
    //            ans = max(ans, mod(n.substr(0, i) + n.substr(i+1), m));
    //        }
    //        cout <<  ans<< endl;
    //    }
    //}
    ll ans = -inf;
    ll cur;
    int i = 0;
    int neww;
    int once = false;
    for( int j= 0; j <l; j++){
        neww = (cur*10L + (int)n[j] - '0') % m;
        if( neww > m && !once){ 
            once = true;
            continue;
        }
        else cur = neww;
        // cerr << cur << endl;
    }
    cout << cur << endl;
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    // int tests = 1;
    int tests;
    cin >> tests;

    while(tests-- > 0)
        run_case();

    // #ifndef ONLINE_JUDGE
    // clock_t end = clock();
    //     cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    // #endif
    return 0;
}

//Debug
//1. size of vi and other containers if applicable
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

