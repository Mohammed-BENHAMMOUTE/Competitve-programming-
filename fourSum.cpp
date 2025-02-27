#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            sort(nums.begin() , nums.end());
            vector<vector<int>> ans;
            for(int i =0 ; i < n-3; i++){
                if(i > 0 && nums[i-1] == nums[i]) continue;
                for(int j = i +1; j < n-2; j++){
                    if (j > i+1 && nums[j] == nums[j-1]) continue;
                    long long  curr = nums[i] + nums[j];
                    int left  = j+1 , right = n-1;
                    long long temp = curr;
                    while(left < right) {
                        temp = curr + (long long )nums[left] + (long long)nums[right];
                        if(temp == target){
                            ans.push_back({nums[i] , nums[j] , nums[left] , nums[right]});
                            while(left  < right && nums[left + 1] == nums[left]) left++;
                            while(left < right && nums[right] == nums[right -1]) right--;
                            left++;right--;
                        }else if(temp < target){
                            left++;
                        }else{
                            right--;
                        }
                    }
                }
            }
            return ans;
        }
    };