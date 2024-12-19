#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
        int rob(vector<int>& nums) {
            if (nums.size() == 1) return nums[0];
            return max(robRange(nums, 0, nums.size()-2), 
                      robRange(nums, 1, nums.size()-1));
        }
private:
    int robRange(vector<int>& nums, int start ,int end) {
        int curr = 0 ;
        int prev1 = 0;
        int prev2 = 0;

        for(int  i =start ; i <= end ; i++){
            curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        };
        return curr;
    }
};