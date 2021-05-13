#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

int gcd(int p, int q){
    while(1){
        if( p == 0 ) return q;
        q %= p;
        if( q == 0 )return p;
        p %= q;
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll p, q;
        if( a*d <= c*b){
            p = (b*c)-(a*d);
            q = b*c;
        }
        else {
            p = a*d-b*c;
            q = a*d;
        }
        ll k= gcd(p, q);
        cout << p/k << "/" << q/k << endl;
    }
    return 0;
}


