#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
const int MOD = 1e9+7;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        int n = nums1.size();
        vector<int> sorted(nums1); 
        sort(sorted.begin(), sorted.end());
        
        long totalDiff = 0;
        int maxDecrease = 0;
        
        for(int i = 0; i < n; i++) {
            int currDiff = abs(nums1[i] - nums2[i]);
            totalDiff += currDiff;
            
            // Find best replacement using binary search
            auto it = lower_bound(sorted.begin(), sorted.end(), nums2[i]);
            
            if(it != sorted.end()) {
                maxDecrease = max(maxDecrease, currDiff - abs(*it - nums2[i]));
            }
            if(it != sorted.begin()) {
                maxDecrease = max(maxDecrease, currDiff - abs(*(--it) - nums2[i]));
            }
        }
        
        return (totalDiff - maxDecrease) % MOD;
    }
};