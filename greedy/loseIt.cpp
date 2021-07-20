#include <algorithm>
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
int N;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> N;
        vector<int> arr(N);
        for (auto &x: arr) cin >> x;
        vi cnt(6, 0);
        for( int i = 0; i < N; i++ ){
            if( arr[i] == 4 ){
                cnt[0]++;
            }
            if( arr[i] == 8 ){
                if( cnt[0] > cnt[1] ) cnt[1]++;
            }
            if( arr[i] == 15 ){
                if( cnt[1] > cnt[2] ) cnt[2]++;
            }
            if( arr[i] == 16 ){
                if( cnt[2] > cnt[3] ) cnt[3]++;
            }
            if( arr[i] == 23 ){
                if( cnt[3] > cnt[4] ) cnt[4]++;
            }
            if( arr[i] == 42 ){
                if( cnt[4] > cnt[5] ) cnt[5]++;
            }
        }
        cout << N - 6*cnt[5] << endl;
    }
    return 0;
}


