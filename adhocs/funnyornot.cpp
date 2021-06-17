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
        vi val;
        int n = (int)s.length();
        for( int i = 1; i < n; i++){
            val.push_back(abs(s[i]-s[i-1]));
        }
        n =(int)val.size();
        bool funny = true;
        for( int i = 0; i < n/2; i++ ){
            if(val[i] != val[n-i-1]){
                funny = false;
                break;
            }
        }
        if( funny ){
            cout << "Funny";
        }
        else cout << "Not Funny";
        cout << endl;
    }
    return 0;
}


