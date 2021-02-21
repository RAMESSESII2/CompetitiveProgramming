//Template
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
int n;
int correctRank[25];
int stOrder[25];
int dp[25][25];
int ans[25];

int lcs(int *correctRank, int *stOrder, int n){ 
    loop(i, 1, n+1){
        loop(j, 1, n+1){
            if(stOrder[i] == correctRank[j]){ 
                dp[i][j] = dp[i-1][j-1] + 1;
                //if current characters are equal then add 1 to the max lcs
            }
            else{ 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            // if not equal then it is equal to max lcs seen so far
        }
    }
    return dp[n][n];
}

void printSequence(int *correctRank, int *stOrder, int n){ 
    int i = n, j = n;
    int k = dp[n][n];
    while(i > 0 && j > 0){ 
        if(stOrder[i] == correctRank[j]){
            ans[k] = stOrder[i];
            k--;
            i-- ; 
            j--;
        }
        else if (dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else j--;
    }
}

void run_case(){
    memset(dp, 0, sizeof dp);
    while( cin>> n )
    {
        loop(i, 1, n+1){
            int x;
            cin >> x;
            correctRank[x] = i;
            //  3 1 2 4 9 5 10 6 8 7 reverse map it 
            //  2 3 1 4 6 8 10 9 5 7
        } 
        loop(i, 1, n+1){
            int x;
            cin >> x;
            stOrder[x] = i;
        }
        print(correctRank, n+1);
        print(stOrder, n+1);
        /* printf("%d", lcs(correctRank, stOrder, n)); */ 
        cout << lcs(correctRank, stOrder, n) << endl;
        printSequence(correctRank, stOrder, n);
        print(ans, dp[n][n]+1);
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


