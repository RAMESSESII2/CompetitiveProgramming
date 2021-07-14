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
        int64_t n;
        cin >> n;
        int64_t res = 1;
        for( int64_t i = n+1 ; i >= n-4 ; i--){
            res *= i;
        }
        // cerr << res << endl;
        res /= int64_t(720);
        int64_t a = 1;
        a = (n-6)*(n-5)/2*(n-4)/3*(n-3)/4*(n-2)/5*(n-1)/6*n/7;
        cout << res+a << endl;
    }
    return 0;
}


