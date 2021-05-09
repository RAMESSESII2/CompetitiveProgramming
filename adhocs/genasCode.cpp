#include <atomic>
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
    // cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<string> arr(n);
        for( auto &x: arr) cin >> x;
        int totalZeros = 0;
        string st = "1";
        bool anyzeros = false;
        for( string x: arr ){
            if( (int)x.size() == 1 ){
                if( x == "0"){
                    anyzeros = true;
                    break;
                }
                if( x != "1") st = x;
            }
            else{
                string t = x;
                sort(t.begin(), t.end());
                int sz =(int)t.size();
                if( t[sz-1] == '1' && t[sz-2] == '0' ){
                    totalZeros += sz-1;
                }
                else st = x;
            }
        }
        if( anyzeros )cout << 0;
        else cout << st + string(totalZeros, '0');
        cout <<endl;
    }
    return 0;
}

