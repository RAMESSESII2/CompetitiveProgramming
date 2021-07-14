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
const int mod = 998244353;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        char prev = s[0];
        ll ans = 0L;
        int i = 1, j = n-2;
        while(i < n){
            if( s[0] != s[i] ) break;
            i++;
        }
        while(j >= 0){
            if( s[n-1] != s[j] ) break;
            j--;
        }
        if( s[0] == s[n-1] ){
            ans = 1L;
            ans *= (i+1)%mod;
            ans *= (n-j)%mod;
        }
        else{
            ans += (i+n-j)%mod;
        }
        cout << ans%mod << endl;
    }
    return 0;
}


