#include<bits/stdc++.h>
using namespace std;
const long long  MOD = 1e9+7; 

void solve() {
  int n,m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> indegree(n+1, 0);

  for(int i =0 ; i < m ; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    indegree[y] +=1;
  }
  vector<int> topo;
  queue<int> q;
  for(int i =1 ; i <= n ; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int current = q.front();
    q.pop();
    topo.push_back(current);

    for(int j : adj[current]) {
      indegree[j] -= 1;
      
      if (indegree[j] == 0) {
        q.push(j);
      }
    }
  }
  vector<int> dp(n+1, 0);
  dp[1] = 1;
  for (auto node : topo) {
    if (dp[node] == 0) continue;
    for (int nei : adj[node]) {
      dp[nei] = (dp[nei] + dp[node]) % MOD;
    }
  }
  // if (dp[n] == 1) { cout << "IMPOSSIBLE" << endl;
  //   return;
  // }
  
  cout << dp[n] % MOD << endl;
}

int main() {
  solve();
  return 0;
}
