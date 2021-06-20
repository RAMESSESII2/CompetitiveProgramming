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
int matrix[1005][1005];

void infiniteMatrix(){
    for( int i = 1; i <= 1000; i++){
        matrix[i][1] = i*(i+1)/2;
        for( int j = 2; j <= 1000; j++ ){
            matrix[i][j] = matrix[i][j-1] + (j-1)+(i-1);
        }
    }
}

int TC;
int main()
{
    file_i_o();
    infiniteMatrix();
    cin >> TC;
    while (TC--)
    {
        int xi, yi, xf, yf;
        cin >> xi >> yi >> xf >> yf;
        ll sum = 0L;
        for( int i = xi; i <= xf; i++ ){
            sum += matrix[i][yi];
        }
        for( int i = yi+1; i <= yf; i++ ){
            sum += matrix[xf][i];
        }
        cout << sum << endl;
    }
    return 0;
}


