#include <algorithm>
#include<bits/stdc++.h>
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

const ll M = (ll)1e5+10;
vector<int> primes;
vector<bool> prime;

void seive(){
    primes = {};
    prime.assign(M, true);
    prime[0] = prime[1] = false;
    for( ll i = 2; i < M; i++ ){
        if( prime[i] ){
            primes.push_back(i);
            for( ll j = (i*i); j < M; j += (long)i ){
                prime[j] = false;
            }
        }
    }
}

ll hcf(ll a, ll b){
    while( 1 ){
        if( a == 0 ) return b;
        b %= a;
        if( b == 0 ) return a;
        a %= b;
    }
}

int TC;
int main()
{
    file_i_o();
    seive();
    cin >> TC;
    while (TC--)
    {
        ll a, b, k;
        cin >> a >> b >> k;
        ll maxm = 0L;
        ll minm = 0L;
        ll g = hcf(a, b);
        if( a == b ) minm = 0L;
        else if( g == a or g == b ) minm = 1L;
        else minm = 2L;

        auto findMax = [](ll a)->ll{
            ll maxm = 0;
            for( auto x: primes ){
                if( x*x > a) break;
                while( a % x == 0 ){
                    a /= x;
                    maxm++;
                }
            }
            // if( a > primes[(int)primes.size()-1] )break;
            if( a > 1 ) maxm++;
            return maxm;
        };
        maxm = findMax(a) + findMax(b);
        // cout << minm << " " << maxm << endl;
        if( k <= maxm && k >= minm ){
            if( k == 1 && minm != 1 ) cout << "NO";
            else cout << "YES" ;
        }
        else cout << "NO";
        cout << endl;
        // cerr << findMax(a) << " " << findMax(b) << endl;
    }
    return 0;
}


