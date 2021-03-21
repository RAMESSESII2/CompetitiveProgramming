#include <cstdio>
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
const int MAX = 1000007;
int n, m, k, p, q;
int t;
std::vector<long long> sqnum;

using namespace std;

void squarenumbers(){
    for( int i = 1; ; i++ ){
        long long cur = i*i;
        sqnum.push_back(cur);
        if( cur >= MAX ) return;
    }
}

int main() {
    squarenumbers();
    // printf("%lld\n", sqnum[int(sqnum.size())-1]);
    scanf("%d", &t);
    while(t-- > 0){
        for( int i = 0 ; i< int(sqnum.size()); i++ ){
            int cur;
            printf("%llu\n", sqnum[i]);
            fflush(stdout);
            scanf("%d", &cur);
            if( cur == 1 )break;
            if( cur == -1 ) break;
        }
    }
}

