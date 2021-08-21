#include<bits/stdc++.h>
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
//given a string -> find the half having most number of c's or if same find the one with most number of (c+1)'s.
//divide into two and calculate answer recursively.
//if length is one and not equal to (c), then return 1;

const int inf = INT_MAX;
string s;

int divideConq(int l, int r, char c){
    if( ( r-l+1 ) == 1 ){
        if( s[l-1] !=  c) return 1;
        return 0;
    }
    int mid = l+(r-l)/2;
    int countL = divideConq(l, mid, c+1);
    countL += (r-l+1)/2 -count(s.begin()+mid, s.begin()+r, c);
    int countR = divideConq(mid+1, r, c+1);
    countR += (r-l+1)/2 -count(s.begin()+l-1, s.begin()+mid, c);
    return min(countL, countR);

}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n;
        cin >> n;
        cin >> s;
        cout <<divideConq(1, n, 'a') << endl;
    }
    return 0;
}


