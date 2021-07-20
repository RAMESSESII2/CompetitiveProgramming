#include<bits/stdc++.h>
#include <iterator>
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
    while (TC--)
    {
        int n;
        cin >> n;
        string sher, mor;
        cin >> sher;
        cin >> mor;
        map<int, int> mp;
        for( auto x: sher ){
            mp[x-'0']++;
        }
        int count = 0;
        for( auto x: mor ){
            bool add = true;
            int i = x-'0';
            while(i >= 0){
                if( mp[i] <= 0 ) i--;
                else{
                    mp[i]--;
                    add = false;
                    break;
                }
            }
            if( add ) count++;
        }
        cout << count << endl;
        mp.clear();
        for( auto x: mor ){
            mp[x-'0']++;
        }
        count = 0;
        for( auto x: sher ){
            bool add = true;
            int i = x-'0';
            i++;
            while(i <= 9){
                if( mp[i] <= 0 ) i++;
                else{
                    mp[i]--;
                    add = false;
                    break;
                }
            }
            if( add ) count++;
        }
        cout << n-count << endl;
    }
    return 0;
}


