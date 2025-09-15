#include<bits/stdc++.h>
using namespace std;

void solve() {
  int n,m; cin >> n >> m;
  vector<vector<int>> adj(n+1);
  vector<int> indegree(n+1, 0);

  for(int i =0 ; i < m ; i++) {
    int x, y; cin >> x >> y;
    adj[x].push_back(y);
    indegree[y] +=1;
  }

  queue<int> q;
  for (int i =1 ;i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> toposort;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    toposort.push_back(top);

    for (int nei : adj[top]) {
      indegree[nei]--;
      if(indegree[nei] == 0) {
        q.push(nei);
      }
    }
  }
  if (toposort.size() != n) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  vector<int> dp(n+1, -1);
  dp[1] = 1;

  vector<int> parent(n+1, -1);
  for(int x : toposort) {
    if (dp[x] == -1) continue;

    for (int v : adj[x]) {
      if (dp[v] < dp[x] + 1) {
        dp[v] = dp[x] + 1;
        parent[v] = x;
      }
    };
  }
  if (dp[n] == -1) {
    cout <<"IMPOSSIBLE" << endl;
    return;
  }
  cout << dp[n] << endl;
  vector<int> path;

  int source = n;
  do {
    path.push_back(source);
    source = parent[source];
  } while (source != -1);
  reverse(path.begin(), path.end());

  for (int i =0; i< path.size(); i++) {
    if (i > 0) cout << " ";
    cout << path[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
