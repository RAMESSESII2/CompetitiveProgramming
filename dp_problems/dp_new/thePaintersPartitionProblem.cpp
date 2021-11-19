#include<bits/stdc++.h>
#include <numeric>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)   r.begin(), r.end()
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

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

const int inf = INT_MAX;
int N, K; 
vector<int> arr;

int partition(int n, int k){
    if( k == 1 ){
        return accumulate(arr.begin(), arr.begin()+n+1, 0);
    }
    if( n == 0){
        return arr[0];
    }
    int best = INT_MAX;
    for(int i = 0; i < n; i++ ){
        best = min(best, max(partition(i, k-1),accumulate(arr.begin(), arr.begin()+n, 0)));
    }
    return best;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> N;
        arr.resize(N);
        for( auto &x: arr ) cin >> x;
        cin >> K;
        cout << partition(N-1, K) ;
    }
    return 0;
}


