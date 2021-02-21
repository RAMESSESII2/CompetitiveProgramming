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
            

int main(){
    clock_t begin = clock();
    file_i_o();
    /* int tests = 1; */
    int tests;
    cin >> tests;
    vl arr(100000);
    arr[1] = 6;
    arr[2] = 15;
    auto isFine = [](int z, int diff){
        for(int j=3; j <= max(diff, int(sqrt(diff))+1); j+=2){
            if( z % j == 0){return false;}
        }
        return true;
    };
    int i = 3;
    int x = 3;
    int a;
    for(i = 3; i <= 10000; i++){
        if( ( i& 1 ) == 0 ){
            arr[i] = arr[i-1];
            continue;
        }
        x = i;
        while(true){
            x += 1;
            if( (x & 1) == 0 ) x++;
            //pick 2 numbers
            while(true){
                if( !isFine(x, i )){ x += 2; }
                else break;
            }
            a = x+i;
            if( (a&1) == 0 ) a ++;
            while(true){
                if( !isFine(a, i )){ a += 2; }
                else break;
            }

            arr[i] = (x*a);
            /* co ut << x << " " << a << endl; */
            /* cout << x << endl; */
            /* cout << arr[i] << endl; */
            break;
        }
    }


    while(tests-- > 0){
        ll d;
        cin >> d;
        cout << arr[d] << endl;
    }


    #ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif
    return 0;
}


