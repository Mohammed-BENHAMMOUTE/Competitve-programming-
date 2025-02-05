#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // we need the rightmost element that is smaller than its next element
        int pivot = n-2;
        while(pivot >= 0 && nums[pivot] >= nums[pivot +1])
        {
            pivot--;
        }
        if(pivot >=0){
            int swappedElement = n-1;
            while (swappedElement >= 0 && nums[pivot] >= nums[swappedElement])
            {
                swappedElement--;
            }
            swap(nums[pivot] , nums[swappedElement]);
        }
        reverse(nums.begin()+pivot +1 , nums.end());
    
    }
};