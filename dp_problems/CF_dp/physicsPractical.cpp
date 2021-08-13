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
// #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // freopen("cerr.txt", "w", stderr);
// #endif
}

const int inf = INT_MAX;
int n;
vi arr;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        cin >> n;
        arr.resize(n);
        for(auto &x: arr) cin >> x;
        sort(all(arr));
        int ans = inf;
        for( int i = 0; i < n-1; i++){
            auto it = lower_bound(all(arr), 2*arr[i]+1); 
            if( it == arr.end() ){
                ans = min(ans, i);
            }
            else{
                int ind = arr.end()-it;
                ans = min(ans, ind+i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}


