#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = accumulate(weights.begin() , weights.end() , 0);
        int l = *max_element(weights.begin(), weights.end());
        int r = sum;
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(check(weights, mid) <= days){
                ans = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        };
        return ans;
    }
    int check(vector<int>& a , int mid){
        int res = 1;
        int cs = 0;
        for(const int& x : a){
            if(cs+x > mid){
                cs = x;
                res++;
            }else{
                cs+=x;
            }
        };
        return res;
    }
};
