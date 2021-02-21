//Template
#include <bits/stdc++.h>
#include<algorithm>
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
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " ";}cout << endl;} 
#define countetbits(i)\
    __builtin_popcount(i)

typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;
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
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */

/* bool sortbysec(const pair<int,int> &a, */ 
/*               const pair<int,int> &b) */ 
/* { */ 
/*     return (a.second < b.second); */ 
/* } */ 
int n;
int maxWt;
vector<int >  weight(1000);
vector<int >  value(1000);
vector<vector< int > > dp(1000+1, vector<int> (1000+1, -1));

//top Down approach  which is efficient in this case
int topD(int id, int  wt){
    if(id == n || wt == 0) return 0;
    int &ans = dp[id][wt];
    if (ans!= -1) return ans;
    if(weight[id-1] > wt) return ans = topD( id + 1, wt );
    return ans = max(topD(id+1, wt), value[id-1] + topD(id + 1, wt - weight[id-1]));
}

void run_case(){
    cin >> n;
    cin >> maxWt;
    value.resize(n);
    loop(i, 0, n) cin >> value[i];
    weight.resize(n);
    loop(i, 0, n) cin >> weight[i];
    cout << topD(0, maxWt) << endl;

    //bottom up approach
    /* loop(i, 1, n+1){ */
    /*     loop(w, 1, maxWt+1){ */
    /*         if(weight[i-1] > w) { */
    /*             dp[i][w] = dp[i-1][w]; */
    /*         } */
    /*         else dp[i][w] = max(dp[i - 1][w], value[i-1] + dp[i - 1][w - weight[i-1]]); */
    /*     } */
    /* } */
    /* cout << dp[n][maxWt] << endl; */
}

int main(){
    clock_t begin = clock();
    file_i_o();
    int tests = 1;

    while(tests-- > 0)
        run_case();

    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


