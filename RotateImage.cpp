#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i+1; j < n ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        for(auto  row : matrix){
            reverse(row.begin() , row.end());
        }
    }
};