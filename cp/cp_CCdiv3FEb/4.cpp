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
int n, m;
char grid[505][505];
int visited[505][505];
vi row;
int dirx[4] = { 0, 0, 1, -1 };
int diry[4]= { 1, -1, 0, 0 };
            
void run_case(){
    cin >> n>> m;
    loop(i, 0, n){ 
        loop(j, 0, m){ 
            cin >> grid[i][j];
        }
    }
    // loop(i, 0, n){ 
    //     loop(j, 0, m){ 
    //         cerr << grid[i][j] << " " ;
    //     }
    //     cerr << endl;
    // }
    int x, y;
    int count;
    loop(i, 0, n){ 
        loop(j, 0, m){ 
            if( grid[i][j] == '1' ) continue;
            if( grid[i][j] == '0' ){
                count = 0;
                loop(k, 0, 4){
                    x = i+dirx[k];
                    y = j+diry[k];
                    if( x < 0 || x >= n || y < 0 || y >= n ) continue;
                    if( grid[x][y] == '1' ) count++;
                    if( count > 1 ){
                        cout << "NO\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "YES\n";

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

