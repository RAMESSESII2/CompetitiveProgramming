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
    cin >> TC;
    while (TC--)
    {
        ll a, b;
        cin >> a >> b;
        if( b > a) swap(a, b);
        if( b+1 == a ){
            cout << 1 <<  " " << 0;
        }
        else if( b == a){
            cout << 0 <<  " " << 0;
        }
        else{
            ll diff = a-b;
            cout << diff << " " << min(b%diff, diff-(b%diff));
        }
        cout << endl;
    }
    return 0;
}


