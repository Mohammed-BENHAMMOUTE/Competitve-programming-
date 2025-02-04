#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
  public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        int currentSum = 0;
        int maxSum = 0;
        for(int i = 0; i < n-1; i++){
            currentSum = arr[i]+ arr[i+1];
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
    }
};