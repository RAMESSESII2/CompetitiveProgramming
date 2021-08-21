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
        ll sum, lim;
        cin >> sum >> lim;
        vector<ll> ans;
        int pos = true;
        for(int i = lim; i > 0; i--){
            int x = i&(-i);
            if(sum >= x){
                sum -= x;
                ans.push_back(i);
            }
        }
        if(sum || ans.empty() ){
            cout << -1;
        }
        else{
            cout << (int)ans.size() << endl;
            for( auto x: ans ) cout << x<< " ";
        }
    }
    return 0;
}


