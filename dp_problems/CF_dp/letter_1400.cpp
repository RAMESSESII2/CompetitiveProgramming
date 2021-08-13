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
// if all of the letters are either in small or all of them in big, then
// return 0;
// else
// there should not be any letter in UPPER CASE to the right of any lower case letter.
// or this can restated as  there should not be any letter in LOWER CASE to the left of any UPPER case letter.
// dpU[i] dpL[i]
// CASE -> u = 1, l = 0;
// if last is U
// then this must be uppper
// else if last is lower
// and this one is lower-> then move ahead
// and if this one is upper-> then move ahead
int n;
string s;
int dp[(int)1e5+20];
int recur2(int ind, int last){
    int &ans = dp[ind];
    if( ind < 0 ) return ans = 0;
    if( ans != -1  ) return ans;
    ans = inf;
    if( 'a' <= s[ind] && s[ind] <= 'z'){
        if( last == 0 ){
            ans = recur2(ind-1, 0);
        }
        else ans = 1+recur2(ind-1, 1); 
    }
    else {
        if( last == 0 ){
            ans = min(1+recur2(ind-1, 0), recur2(ind-1, 1));
        }
        if( last == 1 ){
            ans = recur2(ind-1, 1);
        }
    }
    return ans;
}

int recur(int ind, int last){
    int &ans = dp[ind];
    if( ind >= n ) return ans = 0;
    if( ans != -1  ) return ans;
    ans = inf;
    if( 'a' <= s[ind] && s[ind] <= 'z'){
        if( last == 0 ){
            ans = recur(ind+1, 0);
        }
        else ans = min(1+recur(ind+1, 1), recur(ind+1, 0));
    }
    else {
        if( last == 0 ){
             ans = 1+recur(ind+1, 0); 
        }
        if( last == 1 ){
            ans = recur(ind+1, 1);
        }
    }
    return ans;
}

int TC;
int main()
{
    file_i_o();
    TC = 1;
    // cin >> TC;
    while (TC--)
    {
        cin >> s;
        int n = (int)s.length();
         int l[n], r[n];

    //how many small letters in my left
        l[0]=0;
        int i;
        for(i=1;i<n;i++)
        {
            l[i]=l[i-1];
            if(s[i-1]>='a' && s[i-1]<='z' )
                l[i]++;
        }

        //how many capital letters in my right
        r[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            r[i]=r[i+1];
            if(s[i+1]>='A' && s[i+1]<='Z')
                r[i]++;
        }

        int mn=n;
        for(i=0;i<n;i++)
        {
            //let ith be the point where capital|small occurs
            mn=min(mn,r[i]+l[i]);
        }       
       cout << mn << endl;
    }
    return 0;
}


