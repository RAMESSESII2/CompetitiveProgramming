#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
#include <cstdint>
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
        vector<int> arr(n);
        for( auto &x: arr ) cin >> x;
        int fromLeft = INT_MAX;
        int fromRight = INT_MAX;
        int minEl = *min_element(arr.begin(), arr.end());
        int maxEl = *max_element(arr.begin(), arr.end());
        for( int i = 0; i < n; i++){
            if( arr[i] == minEl or arr[i] == maxEl ){
                fromLeft = i;
                break;
            }
        }
        for( int i = n-1; i >= 0; i--){
            if( arr[i] == minEl or arr[i] == maxEl ){
                fromRight = i;
                break;
            }
        }
        // cerr << fromLeft << " " << fromRight << endl;
        int ans = min(fromLeft+1+n-fromRight, abs(fromLeft-fromRight)+min(fromLeft, n-1-fromRight)+1);
        cout << ans << endl;
    }
    return 0;
}


