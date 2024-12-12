//
// Created by mohammed on 10/12/24.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
       int sum = 0;
        int n = nums.size();

        for ( auto& x : nums) {
            sum += abs(x);
        };
        if ((sum +target) % 2 != 0 || target  > sum) return 0;
        int p = (sum + target) /2;
        std::vector<vector<int>> dp(n+1, vector<int>(p+1 , 0));
        dp[0][0] =1;

        for (int i = 1 ; i <= n; i++) {
            for (int j = 0; j <= p; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }

            }
        }
        return dp[n][p];
    }
};