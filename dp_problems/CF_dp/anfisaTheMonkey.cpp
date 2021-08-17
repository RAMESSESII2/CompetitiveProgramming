#include<bits/stdc++.h>
#include <vector>
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
int n, k,a, b;
string s;
vector<string> vecAns;
int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> k >> a >> b;
        cin >> s;
        int n = (int)s.length();
        int len = n/k;
        int extra = n%k;
        if( len < a or (len+((extra > 0)?1:0)) > b) {
            cout << "No solution";
            continue;
        }
        int pos = 0;
        for(int i = 0; i < k; i++){
            int l = len + ((extra-- > 0)?1:0);
            cout << s.substr(pos, l) << endl;
            pos += l;
        }
    }
    return 0;
}


