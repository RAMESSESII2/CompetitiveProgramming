//TOPIC: Container Inside Container

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector< vector< int > > dp;
    int edge, n1, n2;

    cin >> edge;
    dp.resize(edge);

    for(int i=0; i<edge; i++){
        cin >> n1 >> n2;
        dp[i].push_back( n1 );
        dp[i].push_back( n2 );
    }

    for( const auto &r: dp){
        for( const auto &c: r){
            cout << c << " ";
        }
        cout << endl;
    }
    return 0;
}
