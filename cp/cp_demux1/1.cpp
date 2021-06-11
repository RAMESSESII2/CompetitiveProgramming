#include<bits/stdc++.h>
#include <vector>
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
        vector<int> len(n);
        for( auto &x: len ){
            cin >> x;
        }
        vector<ll> suff(n);
        for( int i= 0; i < n; i++ ){
            suff[i] += suff[i-1] + len[i];
        }
    }
    return 0;
}


