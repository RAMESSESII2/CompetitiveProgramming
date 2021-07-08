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
        int N;
        cin >> N;
        vector<int> arr(2*N);
        for( auto &x: arr ) cin >> x;
        int count = 0;
        for( auto x: arr ){
            if( x&1 ) count++;
        }
        if( count == N){
            cout << "YES";
        }
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}


