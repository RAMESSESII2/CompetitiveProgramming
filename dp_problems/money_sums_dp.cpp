/* You have n coins with certain values. Your task is to find all money sums you can create using these coins. */

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define vi              vector<ll>
#define vs              vector<string>
#define pb              push_back
#define pii             pair<ll,ll>

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
    file_i_o();
    int n;
    cin >> n;
    
    set<long long int> result;

    while(n--){
        int x;
        cin >> x;
        if( result.size() == 0){
            result.insert(x);
            continue;
        }
        vector<long long int> temp;
        for(auto  it = result.begin(); it != result.end(); it++){
            temp.push_back(*it + x);
        }
        result.insert(x);
        for(int i=0; i <= temp.size()-1; i++){
            result.insert(temp[i]);
        }
    }
    cout << result.size() << endl;
    for(auto it = result.begin(); it != result.end(); it++){
        cout << *it << " ";
    }

}


/* INPUT */
/* 4 */
/* 4 2 5 2 */
/* OUTPUT */
/* 9 */
/* 2 4 5 6 7 8 9 11 13 */ 
