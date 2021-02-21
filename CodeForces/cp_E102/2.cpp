//Template
#include <bits/stdc++.h>
using namespace std;
#include <numeric>

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
string s, t;


int gcd(int a, int b)
{
    while (true)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}
            
void run_case(){
    cin >> s >> t;
    if( s == t ){ 
        cout << s << endl;
        return;
    }
    if ( sz(s) == sz(t) ){ 
        cout << -1 << endl;
        return;
    }
    if( sz(s) < sz(t) ){ swap(s, t);}
    int count1 = 1;
    string x;
    bool ifany  = true;
    for(int i = 1; i < sz(s)/2 + 1 ; i++){
        x = s.substr(0, i);
        count1 = 1;
        ifany = true;
        for(int j = i; j < sz(s); j+=i){
            if( s.substr(j, i) != x ){ 
                ifany = false;
                break;}
            count1++;
        }
        if(ifany) break;
    }
    if( !ifany  ) x = s;
    int count2 = 1;
    string y;
    for(int i = 1; i <= sz(t)/2 + 1 ; i++){
        y = t.substr(0, i);
        ifany = true;
        count2 = 1;
        for(int j = i; j < sz(t); j+=i){
            if( t.substr(j, i) != y ){ 
                ifany = false;
                break;}
            count2++;
        }
        if(ifany) break;
    }
    if( !ifany ) y = t;
    /* cout << count1 << " " << count2 << endl; */
    /* cout << x << " " << y << endl; */
    /* cout << x << " " << count1 << " " << y << " " << count2 << endl; */
    if( x != y ){ 
        cout << -1 <<endl;
        return;
    }
    /* if( x == y ){ */
    /*     cout << lcm(count1, count2) << endl; */
    /* } */
    string ans = "";
    loop(i, 0, lcm(count1, count2)){
        ans += y;
    }
    cout << ans << endl;

}

int main(){
    clock_t begin = clock();
    file_i_o();
    /* int tests = 1; */
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


