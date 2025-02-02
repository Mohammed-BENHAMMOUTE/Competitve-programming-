#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
/*
 * we need to find how to replcae what we need to replace
 * what are the indexes that we need to replace and to what range ?
 * [1 ,2 ,3 , 4 ,5 ,6 ,7] index[5] = 4  and k = 3 
 * [5,6,7,1,2,3,4] index[5] = 1
 * [7,6,5,4,3,2,1]
 * index[((X - k -1) + size) % size] swap with index[x]
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n = nums.size();
      k  = k%n;
      reverse(nums.begin() , nums.end());
      reverse(nums.begin() , nums.begin() + k);
      reverse(nums.begin() + k , nums.end());
      
    }
};
