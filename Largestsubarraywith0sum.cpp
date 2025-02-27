#include <bits/stdc++.h>

// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL)

// #define endl "\n"

using namespace std;

class Solution {
    public:
      int maxLen(vector<int>& arr) {
        int n = arr.size();
        map<int,int> index;
        index[0] = -1;
        int sum = 0;
        int mx = 0;
        for(int i =0 ; i < n ; i++) 
        {
            sum += arr[i];
            if(sum ==0) {
                mx = max(mx, i);
            }
            if(index.find(sum) != index.end()){
                mx = max(mx, i-index[sum]);
            }else{
                index[sum] = i;
            }
        }
        return mx;
    }
};