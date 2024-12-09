
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums)  {
        int n = nums.size();
        vector<int> dp(n, 1), counts(n, 1);
        // count represent the number of longest subsequences ending at i.
        int maxlength =1;
        for (int i = 0 ; i < n ; i++) {
            for (int j = i-1;  j >=0 ; j--) {
                if (nums[i] > nums[j] ) {
                    if (dp[i]  < dp[j] + 1) {
                        dp[i] = dp[j]+1;
                        counts[i] = counts[j];
                    }else if (dp[i] == dp[j]+1) {
                        counts[i] += counts[j];
                    }
                }
            }
            maxlength = max(maxlength, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n ;i++) {
            if (dp[i] == maxlength) {
                ans+=counts[i];
            }
        }
        return ans;
    }
};


int main() {
    Solution solution;
    vector<int> v = {1,3,5,4,7};
    cout << solution.findNumberOfLIS(v) << endl;
    return 0;
}
