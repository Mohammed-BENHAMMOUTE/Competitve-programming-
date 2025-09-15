#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color; 
vector<int> cycle_path;

vector<int> parent;

bool dfs(int source) {
    color[source] = 1;
    for (int v : adj[source]) {
        if (color[v] == 1) {
            cycle_path.clear();
            cycle_path.push_back(v);
            int curr = source;
            while(curr != v) {
                cycle_path.push_back(curr);
                curr = parent[curr];
            }
            cycle_path.push_back(v);
            reverse(cycle_path.begin(), cycle_path.end());
            return true;
        }
        if (color[v] == 0) {
            parent[v] = source;
            if(dfs(v)) return true;
        }
    }
    color[source] = 2;
    return false;
}

void solve() {
    int n, m; 
    cin >> n >> m;
    adj.resize(n+1);
    color.resize(n+1, 0); // Now properly initialized as vector<int>
    parent.resize(n+1, -1);
    
    for(int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            if (dfs(i)) {
                // Found a cycle
                cout << cycle_path.size() << "\n";
                for (int x : cycle_path) {
                    cout << x << " ";
                }
                cout << "\n";
                return; // Added return to exit after finding first cycle
            }
        }  
    }
    
    // Added IMPOSSIBLE case
    cout << "IMPOSSIBLE\n";
}

int main() {
    solve();
    return 0;
}


