#include <algorithm>
#include<bits/stdc++.h>
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
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n, k, p;
        cin >> n >> k >> p;
        vi arr(n);
        for( auto &x: arr ) cin >> x;
        int maxm = *max_element(arr.begin(), arr.begin()+n-1);
        int fr = arr[n-1];
        if( fr > maxm || n ==1){
            cout << "Yes\n";
            continue;
        }
        if( k <= 0 && fr <= maxm){
            cout << "No\n";
            continue;
        }
        int diff = maxm-fr+1;
        int numberOfDoses = diff/k;
        if( diff %k >0 ) numberOfDoses++;
        // cerr << numberOfDoses << endl;
        if( numberOfDoses >= p ) cout << "No";
        else cout <<"Yes";
        cout << endl;
    }
    return 0;
}


