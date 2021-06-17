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
        int n, d;
        cin >> n >> d;
        int num;
        cin >> num;
        int left = min(d, 2*n-d);
        int right = max(d, 2*n-d);
        int bottom = min(-d, d);
        int up = max(-d, d);
        // cerr << left << " " << right << endl;
        // cerr << bottom << " " << up << endl;
        while(num--){
            int x, y;
            cin >> x >> y;
            int sum = x+y;
            int diff = x-y;
            if( sum >= left && sum <= right && diff >= bottom && diff <= up){
                cout << "YES";
            }
            else cout << "NO";
            cout << endl;
        }
    }
    return 0;
}


