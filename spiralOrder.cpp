#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int min_x = 0 , min_y = 0;
        int max_x = matrix[0].size() - 1, max_y = matrix.size() - 1;
        vector<int> ans;
        while (min_x <= max_x && min_y <= max_y) {
           for (int i =min_x ; i <=  max_x; i++) {
               ans.push_back(matrix[min_y][i]);
           };
            for (int i = min_y+1 ; i <= max_y ; i++) {
                ans.push_back(matrix[i][max_x]);
            }
            max_x--;
            min_y++;
            // what if the matrix is not a square ?
            if (min_x <= max_x && min_y<= max_y) {
                for (int i = max_x ; i >= min_x ; i--)
                {
                    ans.push_back(matrix[max_y][i]);
                }
                for (int i = max_y -1; i>= min_y ; i--) {
                    ans.push_back(matrix[i][min_x]);
                }
                min_x++;
                max_y--;
            }
        }
        return ans;
    }
};