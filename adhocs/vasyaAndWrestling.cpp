#include<bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
#define ll long long int

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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
        ll n;
        cin >> n;
        vector<ll> arrFirst;
        vector<ll> arrSec;
        ll last = 0;
        ll totalFirst = 0L;
        ll totalSecond = 0L;
        for(int i= 0; i < n; i++){
            ll x;
            cin >> x;
            last = x;
            if( x >= 0 ){ 
                totalFirst += x;
                arrFirst.push_back(x);
                last++;
            }
            else{
                totalSecond += abs(x);
                arrSec.push_back(abs(x));
                last = 0;
            }
        }
        if( totalFirst > totalSecond ){
            cout << "first";
        }
        else if( totalFirst < totalSecond ){
            cout << "second";
        }
        else{
            char w = 'n';
            int i, j;
            i = j = 0;
            while( i < (int)arrFirst.size() && j < (int)arrSec.size() ){
                if( arrFirst[i] == arrSec[i]){
                    i++, j++;
                }
                else if( arrFirst[i] > arrSec[i]){
                    w = 'f';
                    break;
                }
                else{
                     w = 's';
                     break;
                }
            }
            if( w != 'n' ){
                cout << ((w=='f')? "first": "second");
            }
            else if((int)arrFirst.size() > (int)arrSec.size()){
                cout << "first";
            }
            else if((int)arrFirst.size() < (int)arrSec.size()){
                cout << "second";
            }
            else{ 
                cout << ((last == 0)? "second" :"first");
                }
        }
    }
    return 0;
}


