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
        int n, k;
        cin >> n >> k;
        set<int> st;
        while(n--){
            int cur = 0;
            for( int i = 0; i < k; i++ ){
                int x;
                cin >> x;
                cur += (1-x)*(1<<i);
            }
            st.insert(cur);
            // cerr << cur << endl;
        }
        for( auto i: st ){
            for( auto j : st ){
                if(( i| j) == ((1<<k)-1) ) return cout << "YES", 0; 
            }
        }
        cout << "NO";
    }
    return 0;
}


