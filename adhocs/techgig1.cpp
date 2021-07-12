#include<bits/stdc++.h>
#include <vector>
using namespace std;

#define ll long long int
#define ld long long double
#define all(r)  (r.begin(), r.end())
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
const int P_MAX = int(1e6) + 5;

void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}
// ll findMax(ll x){
//     if( prime[x] == 1 ) return 1L;
//     if( x&1L ) return x+1;
//     if( x<= 0 ) return 0;
//     ll ans = 0L;
//     ll rem = 0;
//     for( int i = 0; i < int(primes.size()); i++){
//         if(primes[i] > x) break;
//         if( !((x/primes[i])&1L) ){
//             ans = primes[i];
//             rem = (x/primes[i]);
//             break;
//         }
//     }
//     if( ans == 0L ) return 1L+2L*findMax(x/2L);
//     else return 1L+ ans*(findMax(rem));
// }

ll findmax(ll n){
    ll ans = n;
    for( auto x: primes ){
        if( x*x > n ) break;
        while(  n%long(x) == 0l ){
            n /= long(x);
            ans += n;
        }

    }
    if( n > 2) ans++;
    return ans;
}

int TC;
int main()
{
    sieve(P_MAX);
    TC = 1;

    while (TC--)
    {
        int N;
        cin >> N;
        vector<ll> arr(N);
        for( auto &x: arr ) cin >> x;
        ll ans = 0L;
        for( auto x: arr){
            if( x == 1L ) ans += 1L;
            // else if( prime[x] ) ans += x+1L;
            else{
                ans += findmax(x);
            }
            // cerr << ans << endl;
        }
        cout << ans;
    }
    return 0;
}


