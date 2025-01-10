#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int,vector<int> ,greater<int>> pqmin(arr.begin() , arr.end());
        while(k> 1){
            pqmin.pop();
            k--;
        };
        return pqmin.top();
    }
};
