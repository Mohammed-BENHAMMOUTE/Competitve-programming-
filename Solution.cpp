
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
         int ans = 0;
         for(int i = 0 ; i < grid.size(); i++){
               auto it = lower_bound(grid[i].begin(), grid[i].end(),0);
               ans+= n - distance(grid[i].begin(),it);


         }
};