#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<long long, int> um;
        
        long long sum = 0;
        int maxLen = 0;
        
        um[0] = -1;
        
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            
            if(um.find(sum - k) != um.end()) {
                maxLen = max(maxLen, i - um[sum - k]);
            }
            
            if(um.find(sum) == um.end()) {
                um[sum] = i;
            }
        }
        return maxLen;
    }
};