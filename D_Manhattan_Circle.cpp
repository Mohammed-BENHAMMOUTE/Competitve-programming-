#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void find_center_of_manhattan_circle(int n, int m, const vector<string>& grid) {
    int min_row = numeric_limits<int>::max();
    int max_row = numeric_limits<int>::min();
    int min_col = numeric_limits<int>::max();
    int max_col = numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }

    int center_row = (min_row + max_row) / 2 + 1; // Convert 0-index to 1-index
    int center_col = (min_col + max_col) / 2 + 1; // Convert 0-index to 1-index

    cout << center_row << " " << center_col << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<string> grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        find_center_of_manhattan_circle(n, m, grid);
    }

    return 0;
}
