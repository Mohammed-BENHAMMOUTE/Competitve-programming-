#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = INT_MIN;

void stabilizeMatrix(vector<vector<int>>& matrix, int n, int m) {
    bool changed = true;

    while (changed) {
        changed = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int currentValue = matrix[i][j];
                int maxNeighborValue = INF;

                if (i > 0) maxNeighborValue = max(maxNeighborValue, matrix[i-1][j]);
                if (i < n-1) maxNeighborValue = max(maxNeighborValue, matrix[i+1][j]);
                if (j > 0) maxNeighborValue = max(maxNeighborValue, matrix[i][j-1]);
                if (j < m-1) maxNeighborValue = max(maxNeighborValue, matrix[i][j+1]);

                if (currentValue > maxNeighborValue) {
                    matrix[i][j] = maxNeighborValue;
                    changed = true;
                }
            }
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int rows, columns;
        cin >> rows >> columns;
        vector<vector<int>> matrix(rows, vector<int>(columns));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cin >> matrix[i][j];
            }
        }

        stabilizeMatrix(matrix, rows, columns);
        printMatrix(matrix, rows, columns);
    }

    return 0;
}
