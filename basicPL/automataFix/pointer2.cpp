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
void move(int *(&p), int x){
    p = &x;
    x =10;
}


int TC;
int main()
{
    file_i_o();
    TC = 1;
    while (TC--)
    {
    int* p, x = 100, y = 200;
    p = &x; 
    move(p, y);
    y++;
    printf("%d\n", (*p));
    }
    return 0;
}


