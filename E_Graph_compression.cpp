#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) : parent(n), size(n, 1) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        parent[y] = x;
        size[x] += size[y];
    }

    int get_size(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);
    vector<bool> has_edge(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert to 0-based indexing
        ds.unite(u, v);
        has_edge[u] = has_edge[v] = true;
    }

    int num_components = 0;
    int max_component_size = 0;

    for (int i = 0; i < n; i++) {
        if (has_edge[i] && ds.find(i) == i) {
            num_components++;
            max_component_size = max(max_component_size, ds.get_size(i));
        }
    }

    cout << max(num_components, max_component_size) << endl;

    return 0;
}