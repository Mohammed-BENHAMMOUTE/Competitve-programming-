#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i-1] > nums[i]) {
                count++;
            }
        }
        if(nums[n-1] > nums[0]) {
            count++;
        }
        return count <= 1;
    }
};