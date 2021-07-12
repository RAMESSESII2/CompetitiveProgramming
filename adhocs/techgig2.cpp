#include<bits/stdc++.h>
#include <queue>
#include <system_error>
#include <utility>
#include <vector>
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

const int inf = (int)1e9+9;
int N, R;
vector<vector<pair<int, int> > > adj;
struct comparator{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            if( a.second < b.second ) return 1;
            return 0;
        }
};

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        cin >> N >> R;
        int u, v;
        int c;
        adj.resize(N+1);
        for( int i= 1; i <= N; i++ ) adj[i].clear();
        for( int i = 0; i < R; i++ ){
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
        vector<int> distance(N+1, inf);
        pq.push(make_pair(1, 0L));
        while(!pq.empty()){
            pair<int, int> cur = pq.top();
            pq.pop();
            for( auto x: adj[(int)cur.first]){
                int curDistance = max(0, int(x.second-cur.second));
                if( distance[x.first] > int(curDistance) + int(cur.second) ){
                    distance[x.first] = int(curDistance) + int(cur.second);
                    pq.push({x.first, int(curDistance)+int(cur.second)});
                }
            }
        }
        if( distance[N] == inf ){
            cout << "NOT POSSIBLE";
        }
        else{
            cout << distance[N];
        }
    }

    return 0;
}


