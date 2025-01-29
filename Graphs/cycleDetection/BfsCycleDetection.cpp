#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

class Solution {
public: 
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<int> indegree(V , 0);
        for(int i =0 ; i < V ; i++) 
        {
            for(int x : adj[i])
            {
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V ; i++) {
            if(indegree[i] == 0 ){
                q.push(i);
            }
        };

        int cnt  = 0;
        while(!q.empty()){
            int current = q.front();q.pop();cnt++;
            for(int x : adj[current]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
        }
        return cnt != V;
    };
};