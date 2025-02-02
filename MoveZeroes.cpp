#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
            }
        }
    }
};