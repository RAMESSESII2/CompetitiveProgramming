#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
#include <array>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define vi              vector<ll>
#define vs              vector<string>
#define pb              push_back
#define pii             pair<ll,ll>
#define all(c)          c.begin(), c.end()
#define allr(c)          c.rbegin(), c.rend()
#define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container, element) (container.find(element) != container.end())
#define vpresent(container, element) (find(all(container),element) != container.end())

void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
            
bool compare(int a, int b){
    return a>b;
}


int main(){
//    file_i_o;
    vector< int > v(11);
    vector< long long int > vj;
    if (!v.empty()) cout << "not empty" << endl;
    bool isempty = vj.empty(); 
    cout << isempty << endl;
    cout << v.empty() << endl;
    vector< string > st(10, "mystr");
    vector< string > s(st.begin(), st.end() - (st.size()/2));

    for( vector< string >::iterator it=st.begin(); it != st.end(); it++){
        cout << *it << endl;
    }
    cout << endl << s.size();
    for( int i=0; i!=s.size(); i++){
        cout << s[i] << endl;
    }

    pair< string , pair< int , string> > P;
    P.first = "I'm";
    P.second.first = 1;
    P.second.second = "one";
    cout << P.first << endl;

    vector< int > intarr {2,35,6,2,6,1,7};
    for( vector< int >::iterator it=intarr.begin(); it != intarr.end(); it++){
        cout << *it << endl;
    }
    cout << endl;
    sort(all(intarr));
    for( vector< int >::iterator it=intarr.begin(); it != intarr.end(); it++){
        cout << *it << endl;
    }
    cout << endl;

    sort(allr(intarr));
    for( vector< int >::iterator it=intarr.begin(); it != intarr.end(); it++){
        cout << *it << endl;
    }
    cout << endl;

    vector< int > n(intarr.begin()+intarr.size()/2, intarr.end());
    tr(n, iterat){
        cout << *iterat << endl;
   }
    cout << endl;
    intarr.erase( find(all(intarr), 6), intarr.end());
    tr(intarr, j){
        cout<< *j << endl;
    }
    cout << intarr.size() << endl;
    
}


