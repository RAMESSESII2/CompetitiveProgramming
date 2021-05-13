#include <algorithm>
#include<bits/stdc++.h>
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

ll gcd(ll a, ll b){
    while( 1 ){
        if( a == 0 ) return b;
        b %= a;
        if( b == 0) return a;
        a %= b;
    }
}
struct pat{
    int indI, indJ, x, y;
};

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
        int pos = min_element(arr.begin(), arr.end())-arr.begin();
        vector<pat> ans(n);
        cout << n-1<< endl;
        for(int i = 0; i< n; i++){
            if( pos == i ) continue;
            cout << pos+1 << " " << i+1<< " " << arr[pos] << " " << arr[pos]+abs(pos-i) << endl;
        }
    }
    return 0;
}


