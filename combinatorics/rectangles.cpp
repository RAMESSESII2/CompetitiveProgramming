#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<int64_t>;
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
        int64_t n, m;
        cin >> n  >> m;
        vl rowSum(n);
        vl colSum(m);
        for( int i =0 ; i < n; i++ ){
            int64_t row = 0L;
            for( int j = 0; j < m; j++ ){
                int64_t x;
                cin >> x;
                row += x;
                colSum[j] += x;
            }
            rowSum[i] = row;
        }
        // for(auto x: rowSum) cerr << x << " ";
        // cerr << endl;
        // for(auto x: colSum) cerr << x << " ";
        // cerr << endl;
        int64_t res = 0;
        for( auto x: rowSum ){
            res += (int64_t(1)<<(x)) + (int64_t(1)<< (m-x)) - int64_t(2);
        }
        for( auto x: colSum ){
            res += (int64_t(1)<<(x)) + (int64_t(1)<< (n-x)) - int64_t(2);
        }
        cout << res-(n*m) <<endl;
    }
    return 0;
}


