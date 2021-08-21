#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007LL
#define eps 1e-8
 
using namespace std;
 
int n;
vector<vector<int>> arr;
vector<int> sz;
set<int> s;
 
void dfs(int x,int p)
{
    sz[x]=1;
    for(auto i:arr[x])
    {
        if(i!=p)
            dfs(i,x),sz[x]+=sz[i];
    }
    bitset<5005> bit=1;
    for(auto i:arr[x])
    {
        if(i!=p)
            bit|=bit<<sz[i];
    }
    bit|=bit<<(n-sz[x]);
    for(int i=1;i<n-1;i++)
        if(bit[i]) s.insert(i);
}
 
int main()
{
    cin.tie(0),ios::sync_with_stdio(0);
    cin>>n;
    arr.resize(n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a-1].push_back(b-1);
        arr[b-1].push_back(a-1);
    }
    sz.resize(n);
    dfs(0,0);
    cout<<s.size()<<"\n";
    for(auto i:s)
        cout<<i<<" "<<n-i-1<<"\n";
    return 0;
}
