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
int n;
vi arr;
bool possible(int ind, int sum){
    if( (sum%360 == 0) && ind == n ){
        return 1;
    }
    if( ind >= n) return 0;
    return possible(ind+1, sum-arr[ind]) || possible(ind+1, sum+arr[ind]);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n;
        arr.assign(n, 0);
        for(auto &x: arr) cin >> x;
        bool ans = 0;
        // bool ans = possible(0, 0);
        for( int mask = 0; mask < (1<<n)-1; mask++ ){
            int sum = 0;
            for( int bit = 0; bit < n; bit++ ){
                if( mask&(1<<bit) ){
                    sum += arr[bit];
                }
                else sum -= arr[bit];
            }
            if( sum%360 == 0 ) {
                ans = 1;
                break;
            }
        }
        if( ans) cout << "YES";
        else cout << "NO";
    }
    return 0;
}


