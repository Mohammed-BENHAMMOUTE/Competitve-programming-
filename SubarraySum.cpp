#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n , 0);
        pref[0] = nums[0];
        for (int i = 1; i <n ; i++) {
            pref[i] = pref[i-1] + nums[i];
        }
        std::map<int,int> freq;
        freq[0]=1;
        int count =0;
        for (int i =0 ; i < n ; i++) {
           if (int complement  = pref[i] - k; freq.contains(complement)) {
                count+=freq[complement];
           }
           freq[pref[i]]++;
        }
        return count;
    }
};
