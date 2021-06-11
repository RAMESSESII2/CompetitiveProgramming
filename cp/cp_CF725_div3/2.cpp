#include <algorithm>
#include<bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
#define ll long long int

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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for( auto &x : arr ) cin >> x;
        ll total = accumulate(arr.begin(), arr.end(), 0L);
        if(total%n != 0) {
            cout << -1 << endl;
            continue;
        }
        sort(arr.begin(), arr.end());
        if(n == 1 or  arr[0] == arr[n-1]  ){
            cout << 0 << endl;
            continue;
        }
        auto larg = upper_bound(arr.begin(), arr.end(), total/n);
        if( *larg == total/n ) larg++;
        if( larg == arr.end()  ){
            cout << -1 << endl;
        }
        else{
            cout <<n- (larg-arr.begin()) << endl;
        }
    }
    return 0;
}


