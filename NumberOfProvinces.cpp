#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int connectedComponents = 0;
        for(int i =0 ; i < n ; i++){
            if(!visited[i]){
                connectedComponents++;
                dfs(isConnected , i , visited);
            }
        }
        return connectedComponents;   
    };
private:
    void dfs(vector<vector<int>>& v , int i , vector<int>& visited){
        int n  = v.size();
        visited[i] = 1;
        for(int j = 0 ; j < n ; j++){
            if(v[i][j] == 1 && !visited[j]){
                dfs(v, j , visited);
            }
        };
    };
};