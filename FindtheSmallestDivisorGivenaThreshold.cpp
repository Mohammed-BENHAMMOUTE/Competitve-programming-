    // LeetCode starter code
    #include <iostream>
    #include <vector>
    using namespace std;
    #include <cmath>
    #include <algorithm>

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int end = *max_element(nums.begin(), nums.end());
        int start = 1;
        while (start < end) {
            int mid = start + (end -start)/2;
            int sum = calculatesumdiv(nums, mid);
            if(sum  <= threshold) {
                end = mid;
            }else{
                start = mid + 1;
            }
        }
        return end;
    }
    int calculatesumdiv(vector<int>& v , int div){
        int result = 0;
        for(int& x : v){
            result += ceil(static_cast<double>(x) / div);
        }
        return result;
    }
    
};
