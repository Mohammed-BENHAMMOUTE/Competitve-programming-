#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() <= 1) return;
        
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        int n = nums.size();
        

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        
        int curr = mx;
        for(int i = 1; i < n && curr >= 0; i += 2) {
            while(curr >= 0 && freq[curr] == 0) {
                curr--;
            }
            if(curr >= 0) {
                nums[i] = curr;
                freq[curr]--;
            }
        }
        
        for(int i = 0; i < n && curr >= 0; i += 2) {
            while(curr >= 0 && freq[curr] == 0) {
                curr--;
            }
            if(curr >= 0) {
                nums[i] = curr;
                freq[curr]--;
            }
        }
    }
};