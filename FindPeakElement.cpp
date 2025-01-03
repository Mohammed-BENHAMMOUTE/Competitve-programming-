#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int n = nums.size();
        if( n >1 && nums[0] > nums[1]) return 0;
        if( n >1 && nums[n-1] > nums[n-2]) return n-1;
        int l = 1; int r = n-2;
        int mid  = -1;
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(nums[mid] >  nums[mid+1] && nums[mid] >  nums[mid-1]){
                return mid;
            }else if(nums[mid] <= nums[mid+1]){
                l = mid +1;
            }else if(nums[mid] >= nums[mid+1]){
                r = mid -1;
            }else{
                
            }
        }
        return 0;
    }
};