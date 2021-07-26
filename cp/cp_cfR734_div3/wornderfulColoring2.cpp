#include<bits/stdc++.h>
#include <cstddef>
#include <initializer_list>
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
const int MAX_N = 200 * 1000 + 13;

int ans[MAX_N];
map<int, vector<int>> indices;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        indices.clear();
        memset(ans, 0, n*sizeof(ans[0]));
        for( int i = 0; i < n; i++){
            int x;
            cin >> x;
            //store indeices of the occurances of a particular element
            //if number of occurences is greater than k then we don't need to store it
            if( indices[x].size() < k ) indices[x].push_back(i);
        }
        int m = 0;
        //m is total number of elements to which we can assing colors 
        for( auto e: indices ) m +=e.second.size() ;
        m -= m%k;
        //color stores the current paint color number
        int color = 0;
        for(auto e: indices){
            for(auto i: e.second){
                ans[i] = ++color;
                color %= k;
                //break if we can't assing anymore
                if( --m == 0) goto _output;
            }
        }
_output:
            for( int i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
    }
    return 0;
}


