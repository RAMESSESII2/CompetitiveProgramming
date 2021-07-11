#include<bits/stdc++.h>
#include <numeric>
#include <type_traits>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        ll N;
        cin >> N;
        vector<ll> arr(N);
        ll total = 0L;
        for( auto &x: arr ){ 
            cin >> x;
            total += x;
        }
        if( total % N == 0 || total == 0){
            cout << 0 << endl;
            continue;
        }
        ll mul = total%N;
        cout << (N-mul)*mul << endl;
    }
    return 0;
}


