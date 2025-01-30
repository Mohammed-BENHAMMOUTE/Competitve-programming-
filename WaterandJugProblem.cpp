#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        set<pair<int,int>> visited;
        return dfs(0, 0, target, visited, x, y);
    }
    
    bool dfs(int currentx, int currenty, int target, set<pair<int,int>>& visited, int x, int y) {
        if (currentx + currenty == target) {
            return true;
        }
   
        if (visited.find({currentx, currenty}) != visited.end()) {
            return false;
        }
        
        visited.insert({currentx, currenty});
        
        // Fill jug X
        if (dfs(x, currenty, target, visited, x, y)) return true;
        
        // Fill jug Y
        if (dfs(currentx, y, target, visited, x, y)) return true;
        
        // Empty jug X
        if (dfs(0, currenty, target, visited, x, y)) return true;
        
        // Empty jug Y
        if (dfs(currentx, 0, target, visited, x, y)) return true;
        
        // Pour X to Y
        int pour = min(currentx, y - currenty);
        if (dfs(currentx - pour, currenty + pour, target, visited, x, y)) return true;
        
        // Pour Y to X
        pour = min(currenty, x - currentx);
        if (dfs(currentx + pour, currenty - pour, target, visited, x, y)) return true;
        
        return false;
    }
};