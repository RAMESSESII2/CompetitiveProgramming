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

string timeConversion(string s) {
    string meridian = s.substr(8);
    int hr = stoi(s.substr(0, 2));
    if( meridian == "AM"){
        string ans = s.substr(0, 8);
        if( hr >= 1 && hr < 12  ){
            return ans;
        }
        ans = "00";
        ans += s.substr(2, 6);
        return ans;
    }
    if( hr == 12  ){
        return s.substr(0, 8);
    }
    hr += 12;
    return to_string(hr)+s.substr(2, 6);
}

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
        cout << timeConversion(s) << endl;
    }
    return 0;
}


