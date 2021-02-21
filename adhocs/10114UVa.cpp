//Template
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

/* void file_i_o(){ */
/*     ios_base::sync_with_stdio(0); */
/*     cin.tie(0); */
/*     cout.tie(0); */
/* #ifndef ONLINE_JUDGE */
/*     freopen("in.txt", "r", stdin); */
/*     freopen("out.txt", "w", stdout); */
/* #endif */
/* } */
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */

/* bool sortbysec(const pair<int,int> &a, */ 
/*               const pair<int,int> &b) */ 
/* { */ 
/*     return (a.second < b.second); */ 
/* } */ 
  
vector< double > ptg(102);

void run_case(){
    int months;
    while(scanf("%d", &months) && months>0){
        double dpay, loan;
        int dmon;
        scanf("%lf %lf", &dpay, &loan);
        scanf("%d", &dmon);
        while(dmon--){
            int m;
            double p;
            scanf("%d", &m);
            scanf("%lf", &p);
            for(int i = m; i< 101; i++){
                ptg[i] = p;
            }
        }
        double instl = (loan/months);
        double carworth = dpay + loan;
        double borrows = loan;
        int i = 0;
        carworth *= (1-ptg[0]);
        while(borrows > carworth){
            i++;
            borrows -= instl;
            carworth *= (1-ptg[i]);
        }
        cout << i << ((i>1)?" months": " month") << endl;
    }
    return;
}

int main(){
    /* file_i_o(); */

    run_case();
    return 0;
}


