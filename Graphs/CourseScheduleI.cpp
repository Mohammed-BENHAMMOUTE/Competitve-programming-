#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adj;
        for(int i =0 ; i < n ; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> indegree(numCourses, 0);
        for(int i =0 ; i < numCourses ;i++){
            for(int x : adj[i]){
                indegree[x]++;
            }
        }; 
        queue<int> q;
        for(int i = 0 ; i < numCourses ; i++ ){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty())
        {
            int current = q.front(); q.pop();
            cnt++;
            for(int neighbour : adj[current]){
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return cnt == numCourses;
    }
};