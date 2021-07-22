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

const int inf = 1e7;
int N, K;
vi ans;

int minSkew(int ind){
    if( ind > N ) return inf;
    ans.push_back(ind);
    if( ind + K >= N) return 1;
    return 1+minSkew(ind+2*K+1);
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        cin >> N >> K;
        if( K >= N/2 ){
            cout << 1<< endl;
            cout << max(1,N/2+1);
        }
        else{
            vi cur;
            int a = inf;
            ans.clear();
            for(int i = 1; i <= K+1; i++){
                int c = minSkew(i);
                if( c < a ){
                    cur = ans;
                    a = c;
                } 
                ans.clear();
            }
            cout << (int)cur.size() << endl;
            for(auto x: cur) cout << x << " ";
        }
    }
    return 0;
}


