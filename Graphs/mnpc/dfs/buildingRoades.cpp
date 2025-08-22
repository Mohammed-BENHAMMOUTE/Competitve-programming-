#include<bits/stdc++.h>
using namespace std;

void mark(int index, vector<bool> &visited,const vector<vector<int>>& grid) {
  visited[index] = true;
  for( int neighbour : grid[index]){
    if(!visited[neighbour]) {
      mark(neighbour, visited, grid);
    };
  }
}


void solve() {
  int n, m; 
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for(int i = 0; i < m; i++){
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<bool> visited(n+1, false);
  vector<int> toBeConnected;
  for (int i = 1 ; i <= n; i++) {
    if (!visited[i]) {
      toBeConnected.push_back(i);
      mark(i, visited, adj);
    }
  }
  cout << toBeConnected.size() - 1 << endl;
  for (int i = 1; i < toBeConnected.size(); i++) {
    cout << toBeConnected[i - 1] << " " << toBeConnected[i] << "\n";
  }
};

int main () {
  solve();
  return 0;
}



