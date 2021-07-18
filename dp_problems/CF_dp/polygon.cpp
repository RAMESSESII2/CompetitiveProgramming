#include<bits/stdc++.h>
#include <vector>
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
vector<vector<int> > polygon;

int check(int i, int j){
    return (polygon[i+1][j] || polygon[i][j+1]);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        polygon.assign(n, vector<int>());
        for( int i = 0; i < n; i++){
            string s;
            cin >> s;
            polygon[i].resize(n);
            for( int j = 0; j < n; j++){
                polygon[i][j] = s[j]-'0';
            }
        }
        bool ans = 1;
        for( int i = 0; i < n-1; i++){
            for( int j = 0; j < n-1; j++){
                if((polygon[i][j] == 1) && (!check(i, j) )){
                    ans = 0;
                    break;
                }
            }
        }
        if( ans  ) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}


