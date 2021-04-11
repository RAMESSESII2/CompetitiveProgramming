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
int main()
{
    file_i_o();

    cin >> n;
    int noOf5 = 0;
    ll a = 5;
    while(a <= n ){
        noOf5 += n/a;
        a *= 5;
    }
    cout << noOf5 << endl;


    return 0;
}

