#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n+1, false);
        vector<int> ans;

        for(int i =1 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , visited, ans , adj);
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    void dfs(int s, vector<bool> &visited , vector<int> &ans, vector<vector<int>> &adj){
        visited[s]= true;
        for(int x : adj[s]){
            if(!visited[x]){
                dfs(x, visited , ans , adj);
            }
        }
        ans.push_back(s);
    }
};




