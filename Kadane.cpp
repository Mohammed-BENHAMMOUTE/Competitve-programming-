#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
    int Kadane(vector<int>& nums){
        // {1 ,2} CORRECT = 3 , output =2
        int currentSum = 0;
        int maxSum = INT_MIN;
        for(int x : nums){
            currentSum = max(currentSum + x , x);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};