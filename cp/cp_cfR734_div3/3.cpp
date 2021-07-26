#include<bits/stdc++.h>
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
        vector<string> strings(n);
        string s;
        map<char, int> mp;
        int total = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            strings[i] = s;
            for( auto x: s){ 
                mp[x]++;
                total++;
            }
        }
        int ans = 0;
        bool found = false;
        for( int i = 0; i < 5; i++){
            char cur = char('a'+i);
            int t = total-mp[cur];
            if( mp[cur] > t ){
                found = true;
                cout << n ;
                break;
            }
            else{
                set<pair<double, pii>> st; 
                int toDel = 0;
                int del = 0;
                for( int i = 0; i < n; i++){
                    if( strings[i].find(cur) == string::npos){
                        toDel++;
                        del++;
                    }
                    else{
                        int count = 0;
                        for( auto x: s){
                            if( x== cur) count++;
                        }
                        st.insert({float(count)/float((int)strings[i].size()), {count, strings[i].size()}});
                    }
                    t -= del;
                    if( mp[cur] > t ){
                        ans = max(ans, n-toDel);
                    }
                    else{
                        int count = 0;
                        for(auto [x, y]: st){
                            count++;
                            t -= y.second;
                            mp[cur]-=y.first;
                            if( mp[cur] > t ){
                                ans = max(ans, n-count-toDel);
                            }
                        }
                    }
                }
            }

        }
        if( !found ) cout << ans;
        cout << endl;
    }
    return 0;
}


