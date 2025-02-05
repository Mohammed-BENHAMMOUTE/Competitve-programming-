#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) 
        {
            // Step 2: Find the element just larger than nums[i] and swap them
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) 
            {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        // Step 3: Reverse the elements after the first decreasing element
        reverse(nums.begin() + i + 1, nums.end());
    }
};