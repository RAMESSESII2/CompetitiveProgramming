#include<bits/stdc++.h>
#define ll long long int
using namespace std;

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
int n;
const int mod = 1000000007;

int main()
{
    file_i_o();

    cin >> n;
    ll ans = 1;
    for( int i = 1; i <= n; i++ ){
        ans = (ans*2)%mod;
    }
    cout << ans%mod << endl;


    return 0;
}

