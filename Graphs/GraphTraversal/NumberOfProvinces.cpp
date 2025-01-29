//
// Created by mohammed on 29/01/25.
//

#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

class Solution {
  public:
    int findCircleNum(vector<vector<int>>& isConnected) {
      // isconnected 0/1 is matrix of size n * n
         int n = isConnected.size();
         int counter = 0;
         vector<bool> visited(n, false);
         for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , isConnected);
                counter++;
            }
         }
         return counter;
    }
  private:
    void dfs(int source , vector<vector<int>>& isConnected){
        visited[source] = true;
        int n = isConnected.size();
        for(int i = 0; i < n; i++) {
            if(isConnected[source][i] && !visited[i]) {
                dfs(i, isConnected);
            }
        }
    }
};