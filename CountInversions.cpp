#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
      // Function to count inversions in the array.
      int inversionCount(vector<int> &arr) {
        multiset<int> list;
        int ans = 0;
        for(const int& x : arr){
            if(list.empty()){
                list.insert(x);
                 continue;
            }
            ans+= distance(upper_bound(list.begin(), list.end()))
        }
        return ans;
    }
};

