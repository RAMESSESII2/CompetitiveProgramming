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
    cin >> TC;
    while (TC--)
    {
        int n, k;
        cin >> n >> k;
        vi arr(n);
        for( auto &x: arr) cin >> x;
        int nthMaxEle = k/2 + ((k&1)?1:0);
        if( !(k&1) ) nthMaxEle++;
        // cerr << nthMaxEle << endl;
        vi toSort(all(arr));
        sort(all(toSort));
        int reqEle = toSort[n-(nthMaxEle)];
        // cerr << reqEle << endl;
        int smaller = k/2+((k&1)?1:0);
        int larger = k/2;
        bool added = 0;
        for(int i = 0 ; i < n ; i++ ){
            if( !added && smaller > 0 && arr[i] == reqEle ){
                added = 1;
                cout << arr[i] << " ";
                smaller--;
            }
            if( arr[i] < reqEle && smaller >0 ){
                // cerr << "hereA";
                if( smaller == 1 && !added ) continue;
                cout << arr[i] << " ";
                smaller--;
            }
            if( arr[i] > reqEle && larger >0 ){
                cout << arr[i] << " ";
                larger--;
            }
        }
        cout << endl;
    }
    return 0;
}


