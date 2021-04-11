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

int N, Q;
double X, Y, R;
double x, y;
int k;
const int krange = 10000006;
int numberofcircles[krange];
vector<pair<pair<double, double>, double> > centers;

int main(){
    clock_t begin = clock();
    file_i_o();
    cin >> N >> Q;
    centers.resize(N);
    loop(i, 0, N){ 
        cin >> X >> Y >> R;
        centers[i] = {{X,Y}, R};
    }
    auto euclid = [](pii a, pii b) -> double{ 
        x = a.ff-b.ff;
        y = a.ss-b.ss;
        return (sqrt(x*x+ y*y))  ;
    };
    double distBtwCenters = 0;
    double r1 = 0, r2 = 0;
    double maxm = 0,minm = 0;
    loop(i, 0, N-1){ 
        loop(j, i+1, N){ 
            r1 = centers[i].ss;
            r2 = centers[j].ss;
            distBtwCenters = euclid( centers[i].ff , centers[j].ff );
            // cerr << distBtwCenters << endl;
            // cerr << r1 << " " << r2 << endl;
            // cerr << distBtwCenters << endl;
            // dist[i][j] = distBtwCenters;
            maxm = distBtwCenters+r1+r2;
            if( distBtwCenters >= (r1+r2) ){ 
                minm = distBtwCenters-r1-r2;
                // cerr << "inside" <<1 << endl;
            }
            else{ 
                if( centers[i].ff == centers[j].ff ){ 
                    if( r1 == r2 ){
                        // cerr << "inside" <<2<< endl;
                        minm = 0;
                    }
                    else{
                        // cerr << "inside" <<3<< endl;
                        minm = max(r1, r2)-min(r1, r2); } 
                }
                else if( distBtwCenters < r1 || distBtwCenters < r2){   
                        // cerr << "inside" <<4<< endl;
                    minm = max(r1, r2)-distBtwCenters-min(r1,r2);}
            }
            // cerr << maxm <<" " << minm << endl;
            if( maxm < 0) maxm = 0;
            if( minm < 0  ) minm = 0;
            if( maxm > 1e7 ) continue;
            numberofcircles[(int)ceil(minm)]+=1;
            numberofcircles[(int)floor(maxm)+1]-=1;
        }
    }
    for( int i = 1; i < krange-2; i++){ 
        numberofcircles[i] += numberofcircles[i-1];
    }
    // print(numberofcircles, 17);
    loop(i, 0, Q){ 
        cin >> k;
        cout << numberofcircles[k] << endl;
    }   

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
