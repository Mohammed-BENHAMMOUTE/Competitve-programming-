#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n);
        sort(nums.begin(), nums.end());
        dp[0] = {nums[0]};
        for(int i = 1; i < n ; i++){
            for(int j = i-1; j >= 0; j--){
                if(nums[i] % nums[j] == 0  && dp[j].size()+1 > dp[i].size()){
                    dp[i] = dp[j];
                }
            };
            dp[i].push_back(nums[i]);
        }
        int maxSize = 0;
        vector<int> res;
        for(auto& x : dp) {
            if(x.size() > maxSize){
                res = x;
                maxSize = x.size();
            }
        }
        return res;
    };
};