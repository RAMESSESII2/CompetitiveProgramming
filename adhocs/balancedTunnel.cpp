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
    while (TC--)
    {
        int n;
          cin >> n;
          vector<int> a(n), b(n);
          for (int i = 0; i < n; i++) {
            cin >> a[i];
            --a[i];
          }
          for (int i = 0; i < n; i++) {
            cin >> b[i];
            --b[i];
          }
          vector<int> pos(n);
          for (int i = 0; i < n; i++) {
            pos[b[i]] = i;
          }
          vector<int> c(n);
          for (int i = 0; i < n; i++) {
            c[i] = pos[a[i]];
          }
          int mx = -1, ans = 0;
          for (int i = 0; i < n; i++) {
            if (c[i] > mx) {
              mx = c[i];
            } else {
              ++ans;
            }
          }
          cout << ans << '\n';
    }
    return 0;
}


