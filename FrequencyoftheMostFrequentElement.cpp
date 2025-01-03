#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int left = 0;
        int right = 0;
        long currSum = 0;
        int res = 0;
        int maxElem = 0;
        for (auto num : nums) {
            maxElem = max(maxElem, num);
        }

        vector<int> counts = vector(maxElem + 1, 0);
        for (auto num : nums) {
            counts[num]++;
        }
        
        int index = 0;
        for (int i = 0; i < counts.size(); i++) {
            while (counts[i] > 0) {
                nums[index] = i;
                counts[i]--;
                index++;
            }
        }
        int lastIncrementedRight = -1;
        while (right < nums.size()) {
            if (lastIncrementedRight != right) {
                currSum += nums[right];
                lastIncrementedRight = right;
            }
            int currWindowLen = right - left + 1;

            if (currSum + k >= (long)currWindowLen * nums[right]) {
                res = max(res, currWindowLen);
                right++;
            } else {
                currSum -= nums[left++];
            }
        } 
        return res;
    }
};
