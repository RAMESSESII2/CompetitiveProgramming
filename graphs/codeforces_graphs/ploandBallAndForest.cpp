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
vi arr;
vi parent;

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        parent.assign(n+1, 0);
        for( int i = 1; i <= n; i++){
            cin >> parent[i];
        }
        int count = 0;
        for( int i = 1; i <= n; i++){
            if( parent[i] == i ) count++;
        }
        set<int> st(parent.begin(), parent.end());
        int ans = (int)st.size()-count; 
        ans>>=1;
        cout << count+ans << endl;
    }
    return 0;
}


