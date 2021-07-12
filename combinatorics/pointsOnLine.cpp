#include <algorithm>
#include<bits/stdc++.h>
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
    // cin >> TC;
    while (TC--)
    {
        int n, d;
        cin >> n >> d;
        vl arr(n);
        for( auto &x: arr ) cin >> x;
        ll result = 0l;
        int left = 0;
        int i = 2;
        while( i < n && left < n){
            if( abs(arr[i]-arr[left]) <= d ){
                ll num = long(abs(i-left));
                if( num >= 2 ){
                    result += long(num*(num-1L)/2L);
                } 
                i++;
            }
            else left++;
        }
        // cerr << endl;
        cout << result << endl;
    }
    return 0;
}


