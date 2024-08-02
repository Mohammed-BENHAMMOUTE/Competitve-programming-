#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dfs(int employee, const vector<int>& manager, vector<int>& depth) {
    if (depth[employee] != 0) {
        return depth[employee];
    }
    
    if (manager[employee] == -1) {
        depth[employee] = 1;
    } else {
        depth[employee] = 1 + dfs(manager[employee], manager, depth);
    }
    
    return depth[employee];
}

int main() {
    int n;
    cin >> n;
    
    vector<int> manager(n + 1);
    vector<int> depth(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        cin >> manager[i];
    }
    
    int max_depth = 0;
    for (int i = 1; i <= n; ++i) {
        max_depth = max(max_depth, dfs(i, manager, depth));
    }
    
    cout << max_depth << endl;
    
    return 0;
}