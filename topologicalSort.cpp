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
        vector<int> ans;
        vector<bool> vis(n, false);
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]){
                dfs(i, adj, ans, vis);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& ans, vector<bool>& vis) {
        vis[i] = true;
        for(const int& x : adj[i]){
            if(!vis[x]){
                dfs(x, adj, ans, vis);
            }
        }
        ans.push_back(i);
    }
};




