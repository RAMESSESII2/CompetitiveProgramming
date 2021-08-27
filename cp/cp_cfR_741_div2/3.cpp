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
        int n;
        cin >> n;
        string s;
        cin >> s;
        //1 all 1's ranges greater than n/2
        //2 all 0's ranges greater than n/2
        //3 some 1's precedeed by 0;
        bool solved = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                solved = true;
                if (i >= n / 2) {
                    cout << 1 << " " << i + 1 << " " << 1 << " " << i << endl;
                    break;
                } else {
                    cout << i + 2 << " " << n << " " << i + 1 << " " << n << endl;
                    break;
                }
            }
        }
        if (!solved) {
            cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
        }
    }
    return 0;
}


