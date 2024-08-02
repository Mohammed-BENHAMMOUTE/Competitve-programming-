#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10004;

vector<int> graph[MAX_N];
bool colored[MAX_N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        colored[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Alice" << endl;

    for (int round = 0; round < n; round++) {
        bool adjacent_uncolored = false;
        for (int u = 1; u <= n; u++) {
            if (!colored[u]) {
                for (int v : graph[u]) {
                    if (!colored[v]) {
                        adjacent_uncolored = true;
                        break;
                    }
                }
                if (adjacent_uncolored) break;
            }
        }

        if (adjacent_uncolored) {
            cout << "1 2" << endl;
        } else {
            cout << "1 3" << endl;
        }

        int vertex, color;
        cin >> vertex >> color;
        colored[vertex] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}