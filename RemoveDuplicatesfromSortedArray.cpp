#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n  = nums.size();
        int index = 1;
        for(int i = 1; i < nums.size() ;i++){
            if(nums[i] != nums[i-1]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};