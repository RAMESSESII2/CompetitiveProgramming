#include<bits/stdc++.h>
using namespace std;


                
class Solution {
public:
    void dfs(int node, string &soFar, string &ans, vector<vector<int> > &next, vector<int> isTerminal){
        if( (int)soFar.length() > (int)ans.length()) ans = soFar;
        for(int i = 0; i < 26; i++){
            int t = next[node][i];
            if(t!=0 && isTerminal[t] ){
                soFar += string(1, i+'a');
                dfs(t, soFar, ans, next, isTerminal); 
                soFar.pop_back();
            }
        }
    }
    string longestWord(vector<string>& words) {
        vector<vector<int> > next(30001, vector<int>(26));
        vector<int> isTerminal(30001, 0);
        int N = 0;
        for( auto x: words){
            int node = 0;
            for( auto ch: x){
                int &t = next[node][ch-'a'];
                if( t == 0) t = ++N;
                node = t;
            }
            isTerminal[node] = 1;
        }
        string soFar = "";
        string ans = "";
        dfs(0, soFar, ans, next, isTerminal);
        return ans;
    }
    
};
