#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long long double
#define all(c)  c.begin(), c.end()
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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        ll n;
        cin >> n;
        vi arr(n);
        for( auto &x: arr ) cin >> x;
        sort(all(arr));
        if( arr[0] == arr[n-1] ){
            cout << 0 << " " << (n*(n-1L))/2L << endl;
        }
        else{
            ll countS = 1L;
            ll countL = 1L;
            int i = 1;
            while(i<n-1){
                if( arr[i] != arr[i-1] )break;
                i++;
                countS++;
            }
            i = n-2;
            while(i>=0){
                if( arr[i] != arr[i+1] )break;
                i--;
                countL++;
            }
            cout << arr[n-1]-arr[0] << " " << countS*countL << endl;
        }
    }
    return 0;
}

