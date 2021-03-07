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
typedef pair< ll,ll > pll;
typedef pair< int, int> pii;

typedef vector< long long int > vl;
typedef vector< int > vi;
typedef vector< pii > vpii;
typedef vector< pll > vpll;
typedef vector< string > vs;
typedef vector< double > vd;

typedef vector< vi > vvi;
typedef vector< vl > vvl;



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
int h, m;
string s;
int hh, mm; 
map<int, int> mp;
vi arr;
            
void run_case(){
    cin >> h >> m;
    cin >> s;
    hh = (s[0]-'0')*10 + s[1]-'0';
    mm = (s[3]-'0')*10 + s[4]-'0';
    cerr << hh << ":" << mm << endl;
    auto valid = [](const int &x)->int{ 
        string temp = to_string(x);
        if( sz(temp) == 1 ) temp = "0"+temp;
        string ans = "";
        for( int i = 1; i >= 0; --i){ 
            if( mp[temp[i]-'0'] == -1 )return 100006;
            ans += char(mp[temp[i]-'0'] + '0');
        }
        return stoi(ans);
    };
    auto good = [](const int &a)->string{ 
        string c = to_string(a);
        if( a < 10 ) c = "0"+c;
        return c;
    };
    while( 1 ){
        if( mm == m ){
            hh++, mm = 0;
        }
        if( h == hh ) hh = 0;
        if( valid(mm) < h && valid(hh) < m ){ 
            cout << good(hh) << ":"<< good(mm) << endl;
            break;
        }
        mm++;
    }
}

int main(){
    clock_t begin = clock();
    // sieve(P_MAX);
    file_i_o();
    mp[1] = 1;
    mp[2] = 5;
    mp[5] = 2;
    mp[3] = -1;
    mp[4] = -1;
    mp[6] = -1;
    mp[7] = -1;
    mp[9] = -1;
    mp[8] = 8;
    mp[0] = 0;
    // int tests = 1;
    int tests;
    cin >> tests;

    while(tests-- > 0)
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

