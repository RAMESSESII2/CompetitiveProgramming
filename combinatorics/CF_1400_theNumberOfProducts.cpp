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
    while (TC--)
    {
        ll n;
        cin >> n;
        vi arr(n);
        for( auto &x: arr ) cin >> x;
        int bal, cnt1, cnt2;
        bal = cnt1 = cnt2 = 0;
        //bal -> number of neg elements
        //cnt1 -> theere is an even number of neg elements before them
        //cnt2 -> theere is an odd number of neg elements before them
        ll ans = 0L;
        for( int i = 0; i < n; i++ ){
            if(!(bal&1)){
                cnt1++;
            }
            else cnt2++;
            if( arr[i] < 0 ) bal++;
            if( !(bal&1) ){
                ans += cnt1;
            }
            else ans += cnt2;
        }
        ll sec = (n)*(n+1L)/2l;
        cout << sec - ans << " " << ans << endl;
    }
    return 0;
}


