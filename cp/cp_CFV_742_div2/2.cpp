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
        int a, b;
        //a should be the MEX of the required array
        //b should be the XOR of the required array
        // XOR-> 0 0 = 0, 1 0 = 1, 0 1 = 1, 1 1 = 0;
        cin >> a >> b;
        //let's find the XOR of all in the range 0 to a-1;
        int res[] = {a-1, 1, a, 0};
        int xorOfRange = res[(a-1)%4];
        // cerr << a-1 << " " << xorOfRange << endl;
        if( xorOfRange == b ){
            cout << a << endl;
            continue;
        }
        int ans = a;
        if( (xorOfRange ^ b) == a ){
            ans += 2;
        }
        else ans++;
        cout << ans << endl;
    }
    return 0;
}


