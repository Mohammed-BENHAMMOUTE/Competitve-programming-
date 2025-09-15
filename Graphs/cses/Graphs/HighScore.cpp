#include <bits/stdc++.h>
#include <tuple>
using namespace std;


void solve() {
  int n, m; cin >> n >> m;
  vector<long long> dist(n+1, LLONG_MAX);
  vector<tuple<int,int,int>> edges;

  for (int i =0 ; i < m ; i+= 1) {
    int x, y, w; cin >> x >> y >>w;
    edges.push_back({x, y, -w});
  };
  dist[1] = 0;
  for(int i = 0 ; i < n-1; i += 1) {
    for (auto [x, y, w] : edges) {
      if (dist[x] != LLONG_MAX && dist[x] + w < dist[y]) {
        dist[y] = dist[x] + w;
      }
    }
  }
  vector<int> affected(n+1, 0);
  for (auto [x, y, w] : edges) {
    if (dist[x] != LLONG_MAX && dist[x] + w < dist[y]) {
      affected[y] = 1;
    }
  }
  queue<int> q;
  for(int i = 1 ; i <= n; i++) {
    if(affected[i]) q.push(i);
  }
  vector<vector<int>> adj(n+1);
  for (auto [s,d, w] : edges) {
    adj[s].push_back(d);
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for(int nei : adj[curr]) {
      if (!affected[nei]) {
        affected[nei] = 1;
        q.push(nei);
      }
    }
  }
  if (affected[n]) {
    cout << -1 << endl;
    return;
  }
  cout << -dist[n] << endl;
}

int main() {
  solve();
  return 0;
}
