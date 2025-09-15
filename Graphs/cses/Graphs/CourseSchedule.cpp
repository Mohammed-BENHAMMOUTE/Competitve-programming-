#include<bits/stdc++.h>
using namespace std;

void KahnTopologicalSort(int n, vector<vector<int>> &adj) {
    vector<int> indegree(n + 1, 0);
    // Calculate indegrees.
    for (int i = 1; i <= n; i++) {
        for (int u : adj[i]) {
            indegree[u]++;
        }
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> res;
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for (int son : adj[curr]) {
            indegree[son]--;
            if(indegree[son] == 0) {
                q.push(son);
            }
        }
    }
    
    if (res.size() == n) {
        for (int x : res) {
            cout << x << " ";
        }
        cout << "\n";  
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

void solve() {
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> adj;
    adj.resize(n + 1); // ← THIS LINE WAS MISSING!
    
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
    }
    
    KahnTopologicalSort(n, adj);
    return;
}

int main() {
    solve();
    return 0;
}

/*
The issue was:
- vector<vector<int>> adj; creates an empty 2D vector
- adj[x].push_back(y) tries to access adj[x] which doesn't exist
- This causes undefined behavior/runtime error

The fix:
- adj.resize(n + 1); creates n+1 empty vectors (indices 0 to n)
- Now adj[x].push_back(y) works correctly

Your algorithm logic was perfect - just this initialization issue!
*/
