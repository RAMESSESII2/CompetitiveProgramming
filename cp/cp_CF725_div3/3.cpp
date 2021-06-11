#include <algorithm>
#include<bits/stdc++.h>
#include <cstdlib>
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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> arr(n);
        for( int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort( arr.begin(), arr.end());
        auto calc = [&](int r)->ll{
            ll ans = 0L;
            for( int i = 0, j = n-1; i < n; i++ ){
                while( j > i && arr[i] + arr[j] > r ) j--;
                ans += max((long)i-j, 0L);
            }
            return ans;
        };
        cout << calc(r)-calc(l-1) << endl;
    }
    return 0;
}


