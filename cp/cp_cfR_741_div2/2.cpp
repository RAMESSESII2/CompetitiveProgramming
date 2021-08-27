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

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int k;
        cin >> k;
        vector<char> s(k);
        for( auto &x:s ) cin >> x;
        vector<int> poss = {1, 4, 6, 8, 9, 22, 25, 27, 52, 55, 57, 32, 33, 35, 75, 77, 72};
        int siz = (int)s.size();
        for( auto x: poss){
            int j = (int)(to_string(x).length());
            int m = 0;
            for( int i = 0; i < siz && m < j; i++){
                if( to_string(x)[m] == s[i] ){
                    m++;
                }
            }
            if( m == j ){
                cout << j << endl;
                cout << x << endl;
                break;
            }
        }
    }
    return 0;
}


