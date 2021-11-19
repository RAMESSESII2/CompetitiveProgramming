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
int n, q;
vector<int> ftree;

void update(int ind, int x){
    while( ind > 0 && ind <= n ){
        ftree[ind] += x;
        ind += (ind& (-ind));
    }
}

int sum(int i){
    int s = 0; 
    while(i > 0){
        s += ftree[i];
        i -= (i&(-i));
    }
    return s;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> n >> q;
        ftree.resize(n+1);
        for(int i = 0;i < n; i++){
            int val;
            cin >> val;
            update(val, 1);
        }
        for(int i = 0;i < q; i++){
            int k;
            cin >> k;
            if( k > 0){
                update(k, 1);
            }
            else{
                k = -1*k;
                int low = 0, high = n;
                while( high > low){
                    int mid = low+ (high-low)/2;
                    int val = sum(mid);
                    if( k <= val ) high = mid;
                    else low = mid+1;
                }
                // cerr << low << endl;
                update(low, -1);
            }
        }
        int ans = sum(n);
        // cerr << ans << endl;
        if( !ans ) cout << 0 << endl;
        else {
            int low = 0, high = n;
            while( high > low ){
                int mid = low+ (high-low)/2;
                int val = sum(mid);
                if( ans <= val ) high = mid;
                else low = mid+1;
            }
            cout << low << endl;
        }
    }
    return 0;
}


