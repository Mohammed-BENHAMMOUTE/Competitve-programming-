#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
  int n,m; cin >> n >> m;
  vector<vector<pair<int,int>>> adj(n+1);
  for (int i =0 ; i < m; i++) {
    int a, b, c;  cin >> a >>b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  vector<bool> visited(n+1, false);
  ll sum = 0;
  pq.push({0,1});
  while (!pq.empty()) {
    auto [weight, next] = pq.top();pq.pop();
    if (visited[next]) continue;
    sum += weight;
    visited[next] = true;
    for (auto [num,w] : adj[next]) {
      if (!visited[num]) {
        pq.push({w, num});
      }
    }
  }

  for (int i =1; i <= n; i++) {
    if (!visited[i]) {
      cout << "IMPOSSIBLE" <<endl;
      return;
    }
  }
  cout << sum << endl;
}

int main (int argc, char *argv[]) {
  solve();
  return 0;
}
