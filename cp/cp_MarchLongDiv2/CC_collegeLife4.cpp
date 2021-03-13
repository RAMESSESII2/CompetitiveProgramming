//===============Template==================
#include <bits/stdc++.h>
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


//sieve of eratosthenes 
vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
const int P_MAX = int(1e5) + 5;
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

// __gcd(m, n)
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
int N, E, H;
vpii prices;

int possibleItems(int e, int h){ 
    int cakes = min(e, h);
    e -= cakes;
    h -= cakes;
    return cakes + e/2 + h/3;
}

int binarysearch( int r, int type) {
    int e, h;
    int l = -1;
    while (r-l > 1) {
        e = E, h = H;
        int mid = l + (r - l) / 2;
        {
            if( type == 1) e = E-mid*2;
            else if( type == 2 ) h = H -mid*3;
            else{
                e = E - mid;
                h = H - mid;
            }
        }
        if (possibleItems(e, h) >= N-mid)
            l = mid;
        else
            r = mid;
    }
    l++;
    e = E, h = H;
    if( type == 1) e = E-l*2;
    else if( type == 2 ) h = H -l*3;
    else{
        e = E - l;
        h = H - l;
    }
    if( possibleItems(e, h) >= N-l) return l;
    return l-1;
}

void run_case(){
    cin >> N >> E >> H;
    tuple<int, int, int> original = {N, E, H};
    prices.resize(4);
    loop(i, 1, 4){
        cin >> prices[i].ff;
        prices[i].ss = i;
    }
    int total = possibleItems(E, H);
    if(total < N ){
        cout << -1 << endl;
        return;
    }
    int finalPrice = inf;
    vi arr(3);
    loop(i, 0, 3)arr[i] = i+1;
    do{
        tie(N, E, H) = original;
        // cerr << N <<  E << H;
        int getN;
        int totalPrice = 0;
        for(int i = 0; i < 3; i++){
            if( N == 0 ) continue;
            if(prices[arr[i]].ss == 1){
                getN = binarysearch(E/2, 1);
                getN = min(getN, N);
                // cerr << "Omelettes " << getN << endl;
                E -= getN*2;
                N -= getN;
                totalPrice += getN*prices[arr[i]].ff;
            }
            if(prices[arr[i]].ss == 2){
                getN = binarysearch(H/3, 2);
                getN = min(getN, N);
                // cerr << "shaekes " << getN << endl;
                H -= getN*3;
                N -= getN;
                totalPrice += getN*prices[arr[i]].ff;
            }
            if(prices[arr[i]].ss == 3){
                getN = binarysearch(min(E, H), 3);
                getN = min(getN, N);
                // cerr << "cake " << getN << endl;
                E -= getN;
                H -= getN;
                N -= getN;
                totalPrice += getN*prices[arr[i]].ff;
            }
        }
        // cerr << totalPrice << endl;
        finalPrice = min(finalPrice, totalPrice);
    }while( next_permutation(all(arr)) );
    // sort(all(prices));
    // for(int i = 1; i < 4; i++){
    //     if(prices[i].ss == 1){
    //         getN = binarysearch(E/2, 1);
    //         getN = min(getN, N);
    //         cerr << "Omelettes " << getN << endl;
    //         E -= getN*2;
    //         N -= getN;
    //         totalPrice += getN*prices[i].ff;
    //     }
    //     if(prices[i].ss == 2){
    //         getN = binarysearch(H/3, 2);
    //         getN = min(getN, N);
    //         cerr << "shaekes " << getN << endl;
    //         H -= getN*3;
    //         N -= getN;
    //         totalPrice += getN*prices[i].ff;
    //     }
    //     if(prices[i].ss == 3){
    //         getN = binarysearch(min(E, H), 3);
    //         getN = min(getN, N);
    //         cerr << "cake " << getN << endl;
    //         E -= getN;
    //         H -= getN;
    //         N -= getN;
    //         totalPrice += getN*prices[i].ff;
    //     }
    // }
    cout << finalPrice << endl;
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
//1. size of vi and other containers if applicable
//2. look for type conversion, char to int
//3. look for declaration of large arrays.

