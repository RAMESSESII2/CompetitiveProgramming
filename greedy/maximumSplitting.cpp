#include<bits/stdc++.h>
#include <climits>
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

int n;
int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        if( n <= 3) cout << -1;
        else if( n==4 || n == 6 || n == 9 ) cout << 1;
        else if( n == 5 || n == 7 || n == 11 )cout << -1;
        else if( n == 8 or n == 10 or n == 13 or n == 15 ) cout << 2;
        else{
            int rem = n%4;
            if( rem ==  0) cout << n/4;
            else if (rem == 1) cout << n/4-1;
            else if (rem == 2) cout << n/4;
            else if (rem == 3) cout << n/4-1;
        }
        cout << endl;
    }
    return 0;
}


