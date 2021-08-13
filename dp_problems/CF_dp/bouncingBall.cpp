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
const int MAX = (int)1e5+9;
int n, k, p;
vector<char> arr;
int x, y;

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        cin >> n >> p >> k;
        arr.resize(n);
        string s, s1;
        cin >> s1;
        s = " " + s1;
        cin >> x >> y;
        int pref[MAX+1] = {};

        for( int i = n-k+1; i <= n; i++){
            pref[i] = s[i]-'0';
        }
        for( int i = n-k; i > -1; i--){
            pref[i] = pref[i+k] + (s[i]-'0');
        }
        int ans = inf;
        int len = n-p;
        int cell_del = 0;
        for( int i = p; i < n+1; i++){
            int pans = (len/k + 1 - pref[i])*x + cell_del*y;
            ans = min(ans, pans);
            cell_del++;
            len--;
        }
        cout << ans << endl;
    }
    return 0;
}


