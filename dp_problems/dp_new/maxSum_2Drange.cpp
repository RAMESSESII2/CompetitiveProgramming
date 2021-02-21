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

int n;
vector< vector< int >> matrix(101, vector<int> (100));

int naiveRes(vector< vector< int> > matrix, int n){ 
    int maxSubRect = -9999999;
    loop(i, 1, n+1){ loop(j, 1, n+1){// start coordinate
        loop(k, i, n+1){ loop(l, j, n+1){// end coord
            int subrec = 0;  // sum items in this sub-rectangle
            loop(a, i, k+1){ loop(b, j, l+1){
                subrec += matrix[a][b];
                }
            }
            maxSubRect = max(maxSubRect, subrec);// the answer is here
            }
        }
        }
    }
    return maxSubRect;
}

//O(n^3) 1D DP + greedy (Kadane's) solution
int KadanesRes(vector< vector< int > > matrix, int n){
    int maxSubRect = -39483799;
    loop(l, 1, n+1){ loop(r, l, n+1){
        int subrec = 0;
            loop(row, 1, n+1){
              // Max 1D Range Sum on columns of this row i
                if( l > 0 ) subrec += matrix[row][r] - matrix[row][ l-1 ];
                else subrec += matrix[row][r];
            // Kadane's algorithm on rows
                if( subrec < 0) subrec = 0;
                maxSubRect = max(maxSubRect, subrec);
            }
        }
    }
    return maxSubRect;
}

            
void run_case(){
   cin >> n; 
   matrix.resize(n+1);
   loop(i, 1, n+1){
       matrix[i].resize(n+1);
       loop(j, 1, n+1){
           cin >> matrix[i][j];
           if(j > 1) matrix[i][j] += matrix[i][j - 1];// only add columns of this row i for Kadane's algo
       }
   }
   loop(i, 1, n+1){
       loop(j, 1, n+1){
           cout  << matrix[i][j] << " " ;
       }
       cout << endl;
   }
   /* cout << naiveRes(matrix, n) << endl; */
   cout << KadanesRes(matrix, n) << endl;

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


