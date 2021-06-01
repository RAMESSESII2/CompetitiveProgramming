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

bool run_case(){
    string a;
    cin >> a;
    int checker = 0;
    for(auto x: a){
        int val = x-'a';
        cerr << val ;
        if( (checker&(1<<val)) > 0 ) return false;
        checker |= (1<<val);
        cerr << " " << checker << endl;
    }
    return true;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cout << run_case() << endl;
        cerr << endl;
    }
    return 0;
}


