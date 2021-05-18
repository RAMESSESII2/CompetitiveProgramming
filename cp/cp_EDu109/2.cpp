#include<bits/stdc++.h>
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
        for( auto &x : arr) cin >> x;
        if(arr[0] == 1 && arr[n-1] == n ) {
            bool one = false;
            for( int i = 1; i < n-1; i++){
                if( arr[i] < arr[i-1] ){
                    one = true;
                    break;
                }
            }
            if( one ) cout << 1 <<endl;
            else cout << 0 <<endl;
        }
        else if( arr[0] == 1 || arr[n-1] == n ){
            cout << 1 << endl;
        }
        else if( arr[0] == n && arr[n-1] == 1 ){
            cout << 3 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}


