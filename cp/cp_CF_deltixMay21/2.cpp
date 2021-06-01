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
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for( auto &x: arr ) cin >> x;
        cout << 6*(n/2) << endl;
        for( int i = 0; i < n; i+=2){
            cout << "1 " << i+1 << " " << i+2 << endl;
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "1 " << i+1 << " " << i+2 << endl;
            cout << "1 " << i+1 << " " << i+2 << endl;
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "1 " << i+1 << " " << i+2 << endl;
        }
    }
    return 0;
}


