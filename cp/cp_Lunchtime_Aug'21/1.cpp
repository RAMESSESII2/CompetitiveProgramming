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
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        if( c == a  && b == d ){
            cout << 1;
        }
        else if( c== b && d == a ){
            cout << 1;

        }
        else if( e== b && f == a ){

            cout << 2;
        }
        else if( f== b && e == a ){
            cout << 2;
        }
        else cout << 0;
        cout << endl;
    }
    return 0;
}


