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
        ll h, w;
        cin >> h >> w;
        ll hc, vc;
        cin >> hc >> vc;
        vector<ll> hor(hc);
        vector<ll> ver(vc);
        for( int i = 0; i < hc; i++ ){
            cin >> hor[i];
        }
        for( int i = 0; i < vc; i++ ){
            cin >> ver[i];
        }
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        ll maxDiffH = -1;
        ll maxDiffV = -1;
        maxDiffH = max(maxDiffH, abs(hor[0]-0));
        maxDiffV = max(maxDiffV, abs(ver[0]-0));
        for( int i = 1; i < hc; i++ ){
            maxDiffH = max(maxDiffH, abs(hor[i]-hor[i-1]));
        }
        maxDiffH = max(maxDiffH, abs(hor[hc-1]-h));
        for( int i = 1; i < vc; i++ ){
            maxDiffV = max(maxDiffV, abs(ver[i]-ver[i-1]));
        }
        maxDiffV = max(maxDiffV, abs(ver[vc-1]-w));
        cerr << maxDiffH<< " " << maxDiffV << endl;
        cout << (maxDiffH*maxDiffV)%((int)1e9+7) << endl;
    }
    return 0;
}


