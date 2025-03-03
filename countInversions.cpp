#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
    public:
      // Function to count inversions in the array.
      long long inversionCount(vector<int> &arr) {
        int n = arr.size();
        multiset<int> s; // Using multiset to handle duplicates
        long long count = 0;
        
        for(int i = 0; i < n; i++) {
            // Count elements greater than the current element in the set
            count += distance(s.upper_bound(arr[i]), s.end());
            
            // Add current element to set
            s.insert(arr[i]);
        }
        return count;
      }
};

int main(){

}