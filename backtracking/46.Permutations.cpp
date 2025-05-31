#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int idx , vector<vector<int>>& ans, vector<int> nums) {
      if (idx >= nums.size()) {
         ans.push_back(nums);
      }

      for (int j = idx ; j < nums.size() ; j++) {
         swap(nums[j] , nums[idx]);
         solve(idx + 1 , ans, nums);
         swap(nums[j] , nums[idx]);
      }
   };
public:
   vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;
      int index = 0;
      solve(index , ans , nums);
      return ans;
   }
};