#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Edge{
  int from, to;
   ll weight;
};
void solve() {
  int n , m; cin >> n >> m;
  vector<Edge> edges;
  for(int i =0 ; i < m ; i++) {
    int x, y, w; cin >> x >> y >> w;
    edges.push_back({x, y, w});
  }
  vector<long long> dist(n+1, 0);
  vector<int> parent(n + 1, -1);
  for(int i =0 ; i < n - 1; i++) {
    for (auto edge : edges) {
      int next = edge.to;
      int current = edge.from;
      ll cost = edge.weight;
      if (dist[current] + cost < dist[next]) {
        dist[next] = dist[current] + cost;
        parent[next] = current;
      }
    }
  }
  int source = -1;
  for (auto edge : edges) {
    int next = edge.to;
    int current = edge.from;
    ll cost = edge.weight;
    if (dist[current] + cost < dist[next]) {
      if (source == -1) source = next;
      dist[next] = dist[current] + cost;
      parent[next] = current;
    }
  }

  if (source == -1) {
    cout << "NO" << endl;
    return;
  };
  cout << "YES" << endl;
  for (int i = 0; i < n -1 ; i++) {
    source = parent[source];
  };
  int origin = source;
  vector<int> cycle_nodes;
  do {
    cycle_nodes.push_back(source);
    source = parent[source];
  } while(source != origin);
  cycle_nodes.push_back(origin);
  reverse(cycle_nodes.begin(), cycle_nodes.end());
  for(int i =0 ; i< cycle_nodes.size(); i++) {
    cout << cycle_nodes[i];
    if(i < cycle_nodes.size() - 1) cout << " ";
  }
}


int main() {
  solve();
  return 0;
}
