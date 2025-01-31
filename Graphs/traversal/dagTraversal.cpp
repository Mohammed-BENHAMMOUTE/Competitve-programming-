#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n" 
using namespace std;
/*
in DAG graphs, to find the shortest path from a source to a destination, we can use topological sort
and then relax the edges in the topological order
*/

class Solution
{
private:
    void topoSort(int node, int visited[] , stack<int> &st, vector<vector<pair<int,int>>> &adj){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it.first]){
                topoSort(it.first, visited, st, adj);
            }
        }
        st.push(node);
    }
public:
    int shortestPathDag(vector<vector<pair<int,int>>>& adj, int src , int destination){
        int n = adj.size();
        int visited[n] = {0};
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                topoSort(i , visited, st, adj);
            }
        }
        int dist[n];
        for(int i = 0; i < n; i++){
            dist[i] = INT_MAX;
        }
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it : adj[node]) {
                int v = it.first;
                int weight = it.second;
                if(dist[node] + weight< dist[v]){
                    dist[v] = dist[node] + weight;
                }
            }
        }
        for( int i =0 ; i < n ; i++){
            if(dist[i] == INT_MAX){
                dist[i] = -1;   
            }            
        }
        return dist[destination];
    }
};
