#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> pre(n+1, 0);
        vector<long long> suf(n+1, 0);
        for(int i = 0; i < n; i++) {
            pre[i+1] = pre[i] + nums[i];
        }
        for(int i = n-1; i >= 0; i--) {
            suf[i] = suf[i+1] + nums[i];
        }
        int count = 0;
        for(int i = 0; i < n-1; i++) {
            if(pre[i+1] >= suf[i+1]) {
                count++;DimState, DimCountry, DimArea
            }
        }
        return count;
    }
};