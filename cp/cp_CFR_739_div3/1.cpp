#include<bits/stdc++.h>
#include <string>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)   r.begin(), r.end()
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
    vi dp(5003);
    int j = 0;
    for( int i = 1; i <= 5000; i++){
        if( i%3 !=  0 && to_string(i)[(int)to_string(i).length()-1] != '3'){
            dp[j++] = i;
        } 
    }
    while (TC--)
    {
        int n;
        cin >> n;
        cout << dp[n-1] << endl;
    }
    return 0;
}


