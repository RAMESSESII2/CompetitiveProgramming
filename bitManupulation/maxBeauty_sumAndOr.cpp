#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// void file_i_o(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
//     freopen("cerr.txt", "w", stderr);
// #endif
// }
int TC;
int main()
{
    // file_i_o();
    TC = 1;
    while (TC--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for( auto &x: arr) cin >> x;
        map<int, int> mp;
        for( int i = 0; i < n; i++){
            for( int j = 0 ; j < 31; j++){
                if( arr[i]&(1<<j) ){
                    mp[j]++;
                }
            }
        }
        map<int, int>::reverse_iterator rit;
        rit = mp.rbegin();
        while( rit->second <= 1 ) rit++;
        if( rit == mp.rend() ){
            return (double)10000;
        }
        ll summ = 0L;
        ll orr = 0L;
        set<int> mustHave;
        for( int i = 0; i < n; i++){
            if( arr[i]&(1<<rit->first) ){
                mustHave.insert(arr[i]);
            }
        }
        // for( auto x: mustHave) cerr << x<< " ";
        for( int i = 0; i < n; i++){
            for( auto x: mustHave){
                if( (arr[i]&x) == arr[i]){
                    summ += arr[i];
                    orr |= arr[i];
                    break;
                }
            }
        }
        double ans = (double)summ/(orr*1.0);
        cout << (int)(ans*10000.0) << endl;
    }
    return 0;
}


