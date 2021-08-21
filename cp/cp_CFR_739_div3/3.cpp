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
    cin >> TC;
    ll a[40003];
    auto f = [](const ll &a)->long{
        return 1l*a*a -( a*1l -1l);
    };
    for( ll i = 1l; i < 40000l; i++ ){
        a[i] = 1l*f(i);
    }
    while (TC--)
    {
        ll k;
        cin >> k;
        ll r = 1l, c= 1l;
        for(ll i = 1l; i < 40000l; i++){
            if( a[i] == k ){
                r = i;
                c = i;
                break;
            }
            else if( k > a[i] && k <= i*i ){
                r = i;
                c = i -(k-a[i]);
                break;
            }
            else if( a[i] > k){
                r = i-(a[i]-k);
                c = i;
                break;
            }
        }
        cout << r << " " << c << endl;
    }
    return 0;
}


