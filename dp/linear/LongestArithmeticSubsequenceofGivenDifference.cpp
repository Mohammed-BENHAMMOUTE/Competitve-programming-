#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int longest = 1;
        
        for (int num : arr) {
            dp[num] = dp[num - difference] + 1;
            longest = max(longest, dp[num]);
        }
        
        return longest;
    }
};