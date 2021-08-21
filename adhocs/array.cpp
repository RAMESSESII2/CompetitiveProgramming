#include<bits/stdc++.h>
#include <unordered_map>
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
    // cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n+1);
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++){ 
            cin >> arr[i];
        }
        int l = 0, r = 0;
        set<int> st;
        //keep acuiring until condition
        while( r < n && (int)st.size() < k ){
            ++r;
            st.insert(arr[r]);
            mp[arr[r]]++;
        }
        //lose unnecessary from the start
        if((int)st.size() < k) {
            cout<< -1 << " " << -1 << endl;
            continue;
        }
        while( l <= r ){
            l++;
            if( mp[arr[l]] > 1 ){
                mp[arr[l]]--;
            }
            else break;
        }
        cout << l << " " << r << endl;
        // else cout << -1 << " " << -1 << endl;

    }
    return 0;
}


