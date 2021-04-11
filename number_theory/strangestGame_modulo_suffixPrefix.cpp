#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fo(i,a,n) for(ll i=a;i<n;i++)
#define rfo(i,n,a) for(ll i=n;i>=a;i--)
#define M 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

//Credits of binpow() function :https://cp-algorithms.com/algebra/binary-exp.html
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    clock_t begin = clock();
   	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
	#endif 
    ll t,l,m;
    cin>>t;
    while(t--){
    	cin>>l>>m;
    	ll s_val = 0; // s_val stores the value of the number w.r.t modulo
    	string s; cin>>s;
    	fo(i,0,l){	// calculation of s_val
    	s_val = (s_val + ((s[i]-'0')*binpow(10,l-i-1,m)%m))%m;
        cerr << s_val << endl;
        }
    	ll sum_till_now = 0, ans = s_val; // ans stores the answer of the problem 
    	fo(i,0,l) {// deleting each digit one by one and calculating the value with rest of the digits
    	s_val = (s_val - ((s[i]-'0')*binpow(10,l-i-1,m)%m) + m)%m;
    	ans = max(ans, (sum_till_now + s_val)%m);
    	sum_till_now = (sum_till_now + ((s[i]-'0')*binpow(10,l-i-2,m))%m)%m; // notice that we have our exponent as l-i-2 instead of l-i-1. This is handling division by 10 of prefix part while deleting the digit
    	}
    	cout<<ans<<endl;
    }
    #ifndef ONLINE_JUDGE
    clock_t end = clock();
        cout << "\n\nExecuted In: " << double(end - begin) /CLOCKS_PER_SEC << " seconds" << endl;
    #endif

}
