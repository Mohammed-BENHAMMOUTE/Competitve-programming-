#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
    public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int current = m + n -1;
        int left = m-1, right = n-1;
        while(left >= 0 && right >= 0 ) {
            if(nums1[left] > nums2[right]) {
                nums1[current] = nums1[left];
                left--;
            }else{
                nums1[current] = nums2[right];
                right--;
            }
            current--;
        }
        while(right >= 0 ){
            nums1[current] = nums2[right];
            right--;
            current--;
        }
    }
};