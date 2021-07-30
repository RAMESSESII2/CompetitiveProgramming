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

int gcd(int a, int b){
    while(1){
        if( a == 0 ) return b;
        b %= a;
        if( b == 0 ) return a;
        a %= b;
    }
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n, m;
        cin >> n >> m;
        if( gcd(n, m) > 1 ){
            cout << 0 << endl;
        }
        else if( gcd(n+1, m) > 1 ){
            cout << 1<< endl;
        }
        else if( gcd(n, m+1) > 1 ){
            cout << 1 << endl;
        }
        else cout <<2 << endl;
    }
    return 0;
}


