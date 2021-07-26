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

const int MAX_N = 2 * 100 * 1000 + 13;
const int L = 6;

vector<int> balance[L];

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
        for( int i = 0; i < L; i++) balance[i].clear();
        string s;
        for( int i = 1; i <= n; i++ ){
            cin >> s;
            int initBal = -(int)s.length();
            for( int j = 0; j < L; j++ ){
                balance[j].push_back(initBal);
            }
            for(auto c: s) balance[c-'a'].back() += 2;
        }
        int bestCount = 0;
        int bestLetter = 0;
        for( int i = 0; i < L; i++ ){
            auto &b = balance[i];
            sort( b.rbegin(), b.rend() );
            if( b[0] <= 0) continue;
            int sumBalance = b[0];
            int j = 1;
            for(; j < n && sumBalance > 0; j++){
                sumBalance += b[j];
            }
            if( sumBalance <= 0) j--;
            if( j > bestCount){
                bestCount = j;
                bestLetter = i;
            }
        }
        cout << bestCount << endl;
    }
    return 0;
}


