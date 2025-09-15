#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

class DSU {
  vector<int> size, parent;
  public:
  int components;
  int largest_component;
  DSU(int n) {
    size.resize(n+1, 1);
    parent.resize(n+1);
    components = n;
    largest_component = 1;

    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int k) {
    if (k == parent[k]) {
      return k;
    }
    return parent[k] = findParent(parent[k]);
  }

  void unionByRank(int u, int v) {
    int ul_p_u = findParent(u);
    int ul_p_v = findParent(v);

    if (ul_p_u == ul_p_v) return;
    if (size[ul_p_u] < size[ul_p_v]) {
      size[ul_p_v] += size[ul_p_u];
      parent[ul_p_u] = ul_p_v;
    } else {
      size[ul_p_u] += size[ul_p_v];
      parent[ul_p_v] = ul_p_u;
    }
    largest_component = max(largest_component, max(size[ul_p_u], size[ul_p_v]));
    components -= 1;
    return;
  }
};

void solve() {

  int n, m; cin >> n >> m;
  DSU dsu = DSU(n);
  for (int i =0 ; i < m; i++) {
    int a, b; cin >> a >> b;
    dsu.unionByRank(a,b);
    cout << dsu.components <<  " " << dsu.largest_component << endl;
  }
  return;
}


int main (int argc, char *argv[]) {
  solve();
  return 0;
}
