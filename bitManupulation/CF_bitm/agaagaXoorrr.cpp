#include<bits/stdc++.h>
#include <complex>
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
int n;
vi arr;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        arr.assign(n, 0);
        int xr = 0;
        for( auto &x: arr ){ 
            cin>> x;
            xr ^= x;
        } 
        bool isit = true;
        if( xr == 0){ goto print;}
        else{
        int t = 0, c =0;
        for( int i = 0; i < n; i++ ){
            t ^= arr[i];
            if( t == xr ){
                c++;
                t = 0;
            }
        }
        if( c >= 3 ) isit = true;
        else isit = false;
        }
print:
            if( isit ) cout <<"YES";
            else cout << "NO";
            cout << endl;
    }
    return 0;
}


