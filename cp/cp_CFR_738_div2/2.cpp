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
        vector<char> arr(n);
        for(auto &x: arr) cin >> x;
        for( int i = 0; i < n; i++ ){
            if( arr[i] != '?' ) continue;
            if( i == 0 ){
                int j = i;
                while(j<n && arr[j] == '?' ){j++; continue;}
                if( j == n){
                    arr[i] = 'B';
                }
                else if((j-i)%2 == 0){
                    if( arr[j] == 'R')arr[i] = 'R';
                    else arr[i] = 'B';
                }
                else{
                    if( arr[j] == 'R')arr[i] = 'B';
                    else arr[i] = 'R';
                }
            }
            else arr[i] = (arr[i-1] == 'B')?'R':'B';
        }
        cout << string(all(arr)) << endl;
    }
    return 0;
}


