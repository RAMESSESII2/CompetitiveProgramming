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
int t, w;
ll n;
vector< pair < pii , int > > depGold;
int dp[32][1010];

template< class T>
void printVal( T depGold, int t, int n ){
    int i = n, j = t;
    vl ans;
    while( i > 0 && j > 0 ){
        if(dp[i][j] == dp[i - 1][j - depGold[i-1].ss] + depGold[i-1].ff.ss ){
            ans.push_back(i-1);
            j-= depGold[i-1].ss;
        }
        i--;
        /* else if( dp[i][j] == dp[i -1][j] ){ */
        /*     i--; */
        /*     j--; */
        /* } */
    }
    cout << sz(ans) << endl;
    loopr(i, sz(ans) - 1, -1){
        cout << depGold[ans[i]].ff.ff << " ";
        cout << depGold[ans[i]].ff.ss << endl;
    }
    cout << endl;
}
void run_case(){
    while( cin >> t >> w ){
        cin >> n;
        depGold.resize(n);
        memset( dp, -9987, sizeof(dp));
        loop(i, 0, n){
            int x, y;
            cin >> x >>y;
            depGold[i].first.ff = x;
            depGold[i].ff.ss = y;
            depGold[i].ss = 3*w*x;
        }
        loop(i, 0, n){
            dp[i][0] = 0;
        }
        loop(i, 1, n+1){
            loop(j, 1, t+1){
                if( j >= depGold[i-1].ss ){
                    dp[i][j] = max( dp[i -1][j], dp[i - 1][j - depGold[i-1].ss] + depGold[i-1].ff.ss );
                }
                else dp[i][j] = max( dp[i -1][j], dp[i][j]);
            }
        }
        int ans = *max_element(dp[n], dp[n] + t);
        cout << ans << endl;
        printVal( depGold, t, n );
    }
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

