#include<bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long int

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

int TC;
int main()
{
    file_i_o();
    TC = 1;
    cin >> TC;
    while (TC--)
    {
        int N, M;
        cin >> N >> M;
        vector<pair<pair<int, char>, pair<int, int>> > pos(N);
        for( int i = 0; i < N; i++){
            cin >> pos[i].first.first;
            pos[i].second.first = i+1;
            pos[i].second.second = 1;
        }
        for( int i = 0; i < N; i++){
            cin >> pos[i].first.second;
        }
        sort(pos.begin(),pos.end());
        vector<int > ans(N+1, -1);

        vector<pair<int, int> >oddLeft;
        vector<pair<int, int> >oddRight;
        vector<pair<int, int> >evenLeft;
        vector<pair<int, int> >evenRight;

        for( int i = 0; i < N; i++){
            if(pos[i].second.second){
                if(pos[i].first.first & 1){
                    if( pos[i].first.second == 'R' ){
                        oddRight.push_back({pos[i].first.first, i});
                    }
                    else oddLeft.push_back({pos[i].first.first, i});
                }
                else{
                    if( pos[i].first.second == 'R' ){
                        evenRight.push_back({pos[i].first.first, i});
                    }
                    else evenLeft.push_back({pos[i].first.first, i});
                    }
            }
        }
        int ol = (int)oddLeft.size();
        int oR = (int)oddRight.size();
        int el = (int)evenLeft.size();
        int eR = (int)evenRight.size();
        for( int i = 0; i < min(ol, oR); i++){
            if( oddRight[i].first > oddRight[i].first ) break;
            pos[oddLeft[i].second].second.second = 0;
            pos[oddRight[i].second].second.second = 0;
            ans[pos[oddRight[i].second].first.second] = (oddLeft[i].first + oddRight[i].first)/2;
            ans[pos[oddLeft[i].second].first.second] = (oddLeft[i].first + oddRight[i].first)/2;
        }
        for( int i = 0; i < min(el, eR); i++){
            if( evenRight[i].first > evenLeft[i].first ) break;
            pos[evenLeft[i].second].second.second = 0;
            pos[evenRight[i].second].second.second = 0;
            ans[pos[evenRight[i].second].first.second] = (oddLeft[i].first + oddRight[i].first)/2;
            ans[pos[evenLeft[i].second].first.second] = (oddLeft[i].first + oddRight[i].first)/2;
        }
    }
    return 0;
}


