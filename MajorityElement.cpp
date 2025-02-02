#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

class Solution {
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int condidate = 0;

        for(int num : nums) 
        {
            if(count == 0) {
                condidate  = num;
            }
            count+= (condidate == num ? 1 : -1);
        }
        return condidate;
    }
}