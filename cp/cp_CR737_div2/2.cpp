#include <algorithm>
#include<bits/stdc++.h>
#include <random>
#include <ratio>
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

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        vector<pii> arr(n);
        for( int  i = 0; i < n ;i++){
            cin >> arr[i].first;
            arr[i].second = i+1;
        }
        sort(all(arr));
        for( int  i = 1; i < n ;i++){
            if( arr[i].second != arr[i-1].second+1 ){
                k--;
            }
            if( k < 0) break;
        }
        // cerr << k << endl;
        if( k <= 0 ) cout << "No";
        else cout << "Yes";
        cout << endl;
    }
    return 0;
}


