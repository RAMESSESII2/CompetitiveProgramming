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
        ll n, a, b;
        cin >> n >> a >> b;
        if( b == 1 ){
            cout << "YES";
        }
        else if( a == 1){
            if( (n%b) == 1) cout << "YES";
            else cout << "NO";
        }
        else{
            ll num = 1;
            bool t = true;
            while(num <=n ){
                if( (n-num)%b == 0 ){
                    cout << "YES";
                    t = false;
                    break;
                }
                num*=a;
            }
            if( t )cout << "NO";
        }
        cout << endl;

    }
    return 0;
}

