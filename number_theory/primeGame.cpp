#include <algorithm>
#include<bits/stdc++.h>
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
//sieve of eratosthenes 
// vector<bool> prime;
// vector<int> primes;
// const int P_MAX = int(1e6) + 5;
// void sieve(int maximum) {
//     maximum = max(maximum, 1);
//     prime.assign(maximum + 1, true);
//     prime[0] = prime[1] = false;
//     primes = {};
//     for (int p = 2; p <= maximum; p++)
//         if (prime[p]) {
//             primes.push_back(p);
//             for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
//                 if (prime[i]) {
//                     prime[i] = false;
//                 }
//         }
// }
const int MAX = (int)1e6+9;
vector<bool> isPrime;
vector<int> primes;
void sieve(){
    isPrime.resize(MAX, 1);
    isPrime[0] = isPrime[1] = 0;
    for( ll i = 2; i <= MAX; i++ ){
        if( isPrime[i] == 0 ){
            continue;
        }
        primes.push_back(i);
        for( ll j = i*i; j <= MAX; j+=i){
            if( isPrime[j] ) isPrime[j] = 0;
        }
    }
}

int TC;
int main()
{
    file_i_o();
    sieve();
    // sieve(P_MAX);
    cin >> TC;
    // for( int i = 0; i < 10; i++){
    //     cerr << primes[i] << " ";
    // }
    while (TC--)
    {
        int l, r;
        cin >> l >> r;
        auto minm = lower_bound(primes.begin(), primes.end(), l);
        // cerr << *minm << " ";
        if( *minm > r ) cout << -1 << endl;
        else{
            auto maxm = lower_bound(primes.begin(), primes.end(), r);
            // cerr << *maxm << " ";
            if( *maxm > r) maxm--;
            if( *maxm == *minm ) cout << 0 << endl;
            else cout << *maxm-*minm << endl;

        }
        // cerr << endl;
    }
    return 0;
}


