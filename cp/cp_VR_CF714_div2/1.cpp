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
    cin >> TC;
    while (TC--)
    {
        int N, K;
        cin >> N >> K;
        if(((N&1) && K > N/2) or (!(N&1) && (K>N/2-1))){
            cout << -1 << endl;
            continue;
        }
        int last = N;
        int start = 1;
        vector<int> ans(N);
        for( int i = 1; i < N-1; i+=2){
            if( K == 0) break;
            ans[i] = last--;
            K--;
        }
        for( int i = 0; i < N; i++ ){
            if( ans[i] == 0 ) cout << start++ << " ";
            else cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


