#include<bits/stdc++.h>
#include <set>
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

// if there's any cyclic dependency, then -1
// else there always exists a solution
// which can be found out by using a set data structure
const int inf = INT_MAX;
int n;
vector<set<int>> dependent;
vector<set<int>> determiner;
vector<int> iter;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        dependent.assign(n+1, set<int>());
        determiner.assign(n+1, set<int>());
        iter.assign(n+1, 0);
        int k, v;
        for(int i = 0; i < n; i++){
            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> v;
                dependent[i+1].insert(v);
                determiner[v].insert(i+1);
            }
        }
        for(int i = 1; i <= n; i++){
            cout << i << ": ";
            for( auto x: dependent[i] ) cout << x << " ";
            cout << endl;
        }
        cout << endl;
        for(int i = 1; i <= n; i++){
            cout << i << ": ";
            for( auto x: determiner[i] ) cout << x << " ";
            cout << endl;
        }
        for(int z = 0; z < 2; z++){
        for(int i = 1; i <= n; i++){
            if( dependent[i].empty() ){
                cerr << i << endl;
                iter[i]++;
                for( auto x: determiner[i] ){
                    dependent[x].erase(i);
                    if( dependent[x].empty() ){
                        iter[x] = iter[i];
                        if( x < i ) iter[x]++;
                    }
                }
            }
            determiner[i].clear();
        }
        }
        bool toC = false;
        for(int i = 1; i <= n; i++){
            if( !dependent[i].empty() ){
                toC = 1;
                break;
            }
        }
        if( toC ) {
            cout << -1  << endl;
            continue;
        }
        cout << *max(all(iter)) << endl;
    }
    return 0;
}


