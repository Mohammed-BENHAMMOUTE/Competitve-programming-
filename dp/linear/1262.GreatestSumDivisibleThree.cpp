#include<bits/stdc++.h>
using namespace std;
int maxSumDivThree(vector<int>& nums) {
    vector<int> dp(3, 0);
    for(const int& x : nums) {
        vector<int> temp = dp;
        for(const int& y : temp){
            int z = x + y;
            dp[z%3] = max(dp[z%3], z);
        }
    }
    return dp[0];
}