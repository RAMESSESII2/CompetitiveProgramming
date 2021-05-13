#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>

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
ll n, m;
vi arr;

void run(){
    cin >> n >> m;
    if(  m == 1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    ll x = n;
    ll mul = 10000*n*m;
    ll z = mul;
    cout << x << " " << ((z-x)/n)*n << " ";
    cout << mul <<endl;
}

int TC;
int main()
{
    file_i_o();
    cin >> TC;
    while (TC--)
    {
        run();
    }
    return 0;
}


