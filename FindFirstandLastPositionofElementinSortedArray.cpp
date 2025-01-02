#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin() , nums.end() , target);
        if(it1 == nums.end() || *it1 != target){
            return {-1, -1};
        }
        auto it2 = upper_bound(nums.begin(), nums.end() , target);
        int val1 = distance(nums.begin() , it1);
        int val2 = -1;
        if(it2 != nums.begin()){
            val2 = distance(nums.begin() , it2-1);
        }else{
            return {-1, -1};
        }
        return {val1, val2};
    }
};