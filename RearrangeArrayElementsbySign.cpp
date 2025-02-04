#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos = 0, neg = 1;
        for(const int& x : nums) {
            if(x > 0) {
            ans[pos] = x;
            pos += 2;
            } else {
            ans[neg] = x;
            neg += 2;
            }
        }
        return ans;
    }
};