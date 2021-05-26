#include<bits/stdc++.h>
using namespace std;
#define ll long long int

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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        map<int, int> freq1, freq2;
        int x, y;
        for(int i = 0; i < n; i++){
            cin >>x >> y;
            freq1[x-y]++;
            freq2[y+x]++;
        }
        ll ans = 0L;
        for( auto x: freq1 ){
            if( x.second == 1 ) continue;
            else ans += ((x.second)*(x.second-1)/2);
        }
        for( auto x: freq2 ){
            if( x.second == 1 ) continue;
            else ans += ((x.second)*(x.second-1)/2);
        }
        cout << ans << endl;
    }
    return 0;
}


