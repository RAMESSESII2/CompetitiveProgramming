#include<bits/stdc++.h>
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
int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        int a, b, p;
        cin >> a >> b >> p;
        string s;
        cin >> s;
        int n = (int)s.length();
        vl v(n, 0l);
        for( int i = n-2; i >= 0; i--){
            if( i != n-2 && s[i] == s[i+1] ) v[i] = v[i+1];
            else if (s[i] == 'A') v[i] = v[i+1]+1l*a;
            else v[i] = v[i+1]+1l*b;
        }
        for( int i = 0; i < n;  i++){
            if( v[i] <= 1l*p ){
                cout << i+1 << "\n";
                break;
            }
        }
    }
    return 0;
}


