#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // step 1 find the rotation axis
        int n = nums.size();
        int mx = nums[0];
        vector<int> ar(nums.begin(), nums.end());
        int l = 0; int r = n - 1;
        int ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ar[mid] < mx){
                ans = mid;
                r = mid-1;
            }else{
                l = mid +1;
            }
        };
        int axis = n-ans;
        auto it = lower_bound(ar.begin() , ar.begin() +ans, target);
        if(it!= ar.end()){
            if (*it == target){
                return distance(ar.begin(), it)-1;
            }
        };
        it = lower_bound(ar.begin() +ans , ar.end(), target);
        if(it!= ar.end()){
            if (*it == target){
                return distance(ar.begin(), it)-1;
            }
        }
        return -1;

    }
};

