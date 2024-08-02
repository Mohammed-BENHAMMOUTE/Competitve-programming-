#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    if (n >= m) {
        cout << n - m << endl;
        return;
    }
    
    vector<bool> visited(m*2 + 1, false);
    queue<pair<int, int>> q;
    q.push({n, 0});
    visited[n] = true;
    
    while (!q.empty()) {
        auto [cur, step] = q.front();
        q.pop();
        
        if (cur == m) {
            cout << step << endl;
            return;
        }
        
        if (cur < m && !visited[cur * 2]) {
            q.push({cur * 2, step + 1});
            visited[cur * 2] = true;
        }
        
        if (cur > 1 && !visited[cur - 1]) {
            q.push({cur - 1, step + 1});
            visited[cur - 1] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}