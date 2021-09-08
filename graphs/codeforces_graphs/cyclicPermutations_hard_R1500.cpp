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

const int inf = (int)1e9+7;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        ll n;
        cin >> n;
        ll factorial = 1l, exp = 1l;
        for(int i = 1; i <= n-1; i++){
            factorial *= i;
            exp *= 2l;
            factorial %= inf;
            exp %= inf;
        }
        factorial *= n;
        factorial %= inf;
        factorial -= exp;
        if( factorial <= 0) factorial += inf;
        cout << factorial << endl;
    }
    return 0;
}


