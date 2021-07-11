#include <bits/stdc++.h>
using namespace std;

#define ll              long long int
#define ld              long double
#define mod             1000000007
#define pb              push_back
#define ff              first
#define ss              second
#define inf             1e18
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i=(a); i<b; i++)
#define loopr(i, a, b)  for(int i=(a); i>b; i--)

#define sz(a)           int((a).size())
#define all(c)          c.begin(), c.end()
#define allr(c)         c.rbegin(), c.rend()

#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) \
    (container.find(element) != container.end())
#define vpresent(container, element) \
        (find(all(container),element) != container.end())

#define print(dp, n); \
    loop(i, 0, n){cout << dp[i] << " ";}cout << endl; 
#define print2(dp, n, m); \
    loop(i, 0, n){loop(j, 0, m){cout << dp[i][j] << " ";}cout << endl;} 


typedef vector< long long int > vi;
typedef vector< string > vs;
typedef vector< vi > vvi;
typedef pair< ll,ll > pii;

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
/* bool compare(int a, int b){ */
/*     return a>b; */
/* } */
void build(vi &arr, vi &tree, ll s, ll e, ll tidx){
    if(s == e){
        tree[tidx] = arr[s];
        return;
    }
    ll m = mid(s, e);
    ll l = 2*tidx;
    ll r = 2*tidx + 1;
    build(arr, tree, s, m, l);
    build(arr, tree, m+1, e, r);
    tree[tidx] = tree[l] * tree[r];
}

ll query(vi &tree, ll s, ll e, ll tidx, ll kth){
    if(kth>=tree[tidx]){
        return -1;
    }
    if(s == e){
        return s;
    }
    ll m = mid(s, e);
    if(kth < tree[2*tidx]){
        return query(tree, s, m, 2*tidx, kth);
    }
    else return query(tree, m+1, e, 2*tidx+1, kth-tree[2*tidx]);
}

void update(vi &tree, ll s, ll e, ll tidx, ll ind){
    if(s==e){
        tree[tidx] ^= 1 ;
        return;
    }
    ll m = mid(s, e);
    if( m>=ind){
        update(tree, s, m, 2*tidx, ind);
    }
    else update(tree, m+1, e, 2*tidx+1, ind);
    tree[tidx] = tree[2*tidx] + tree[2*tidx+1];
}


void run_case(){
    ll n, m;
    cin >> n >> m;
    vi arr(n);
    loop(i, 0, n){
        cin >> arr[i];
    }
    vi tree(4*n);
    build(arr, tree, 0, n-1, 1);
    while(m-- > 0){
        ll type, k;
        cin >> type >> k;
        if(type == 1){
            update(tree, 0, n-1, 1, k);
        }
        else{
            cout << query(tree, 0, n-1, 1, k) <<endl;
        }
    }
}

int main(){
    file_i_o();

    int tests = 1;
    while(tests-- > 0)
        run_case();
    return 0;
}

