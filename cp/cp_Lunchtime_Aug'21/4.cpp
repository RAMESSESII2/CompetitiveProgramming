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
        int n;
        cin >> n;
        vi arr(n);
        for( auto &x: arr) cin >> x;
        bool t = false;
        for(int i = 1; i < n; i++){
            if( arr[i]-arr[i-1] != 1 ){
                t = 1;
                break;
            }
        }
        if( t ) cout << 1;
        else cout << n;
        cout <<endl;
    }
    return 0;
}


