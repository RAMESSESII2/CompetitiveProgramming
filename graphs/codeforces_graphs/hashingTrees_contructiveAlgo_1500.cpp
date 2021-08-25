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

const int inf = INT_MAX;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int h;
        cin >> h;
        vi a(h+2);
        vi ans(300000);
        int pos = 0;
        for( int i = 1; i <= h+1; i++ ){
            cin >> a[i];
            if( a[i] > 1 && a[i-1] > 1 ) pos = i;
        }
        if( !pos ){
            cout << "perfect" << endl;
        }
        else{
            cout << "ambiguous\n";
            for(int i = 1; i <= h; i++) a[i+1] += a[i];
            for( int i = 1; i <= h+1; i++){
                for( int j= a[i-1]+1; j <= a[i]; j++ ){
                    ans[j] = a[i-1];
                }
            }
            for(int i = 1; i <= a[h+1]; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
            ans[a[pos]] = a[pos-1]-1;
            for(int i = 1; i <= a[h+1]; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


