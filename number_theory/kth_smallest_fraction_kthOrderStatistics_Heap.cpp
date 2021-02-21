#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <array>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <random>
#include <cassert>
#include <chrono>
#include <cmath>
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define ff              first
#define ss              second
#define inf             1e18
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<=b; i++)
#define loopr(i, a, b)  for(int i=(a); i>=b; i--)

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


typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;

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
class fraction{
    public:
        double value;
        int i; // numerator index
        int j; // denominator index
        fraction(double v, int i, int j){
            this->value = v;
            this->i = i;
            this->j = j;
        }
        bool operator < (const fraction&x) const{
            return value > x.value;
        }
};

pii kthsmallestFrction(vector<int> &arr, int k){
    priority_queue<fraction> pq;
    for(int i=0; i <sz(arr); i++){
        pq.push(fraction(static_cast<double>(arr[i]/arr.back()), i, arr.size()-1));
    }
    while(k-- > 1){
        auto t = pq.top();
        pq.pop();
        t.j = t.j -1;
        pq.push(fraction(static_cast<double>(arr[t.i]/arr[t.j]), t.i, t.j));
    }
    return make_pair(arr[pq.top().i], arr[pq.top().j]);
}
void run_case(){
    ll k =3;
    vector<int> arr = {1,2,3,5};
    pii kth = kthsmallestFrction(arr, k);
    cout << kth.ff << " " << kth.ss << endl;
}

int main(){
    clock_t begin = clock();
    /* file_i_o(); */

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


