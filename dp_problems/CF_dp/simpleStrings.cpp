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

const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        string s;
        cin >> s;
        int n = (int)s.size();
        for( int i = 1; i < n-1 ; i++ ){
            if( s[i] == s[i-1] ){
                s[i] = ((s[i]-'a'+1)%26+'a' != s[i+1])?(s[i]-'a'+1)%26+'a': (s[i]-'a'+2)%26+'a';
            }
        }
        if( n > 1 && s[n-1]==s[n-2]){
            s[n-1] = (s[n-1]-'a'+1)%26 + 'a';
        }
        cout << s << endl;
    }
    return 0;
}


