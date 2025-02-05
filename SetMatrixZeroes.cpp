#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        
        unordered_set<int> rows;
        unordered_set<int> columns;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    columns.insert(j);
                }
            }
        }
        for (int x : rows) {
            fill(matrix[x].begin(), matrix[x].end(), 0);
        }

        for (int y : columns) {
            for (int i = 0; i < n; i++) {
                matrix[i][y] = 0;
            }
        }
    }
};