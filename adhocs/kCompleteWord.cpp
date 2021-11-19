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
const int Max = (int)2e5+9;
int n, k;
string s;
int cnt[Max][27];
int differ(int u, int v){
    int ret = 0, mx = 0;
    for(int j=0; j <26; j++){
        ret += cnt[u][j] + cnt[v][j];
        mx = max(mx, cnt[u][j]+cnt[v][j]);
    }
    return ret-mx;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n >> k >> s;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < 26; j++){
                cnt[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            cnt[i%k][s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans += differ(i, k-1-i);
        }
        cout << ans/2 << endl;
    }
    return 0;
}


