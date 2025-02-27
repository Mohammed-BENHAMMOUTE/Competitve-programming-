#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;
const int MAXNUMBER = 1e4+2;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.empty()) return {};

            sort(intervals.begin() , intervals.end());
            vector<vector<int>> merged;
            merged.push_back(intervals[0]);


            for(int i = 1; i < intervals.size() ; i++) {
                if(intervals[i][0] <= merged.back()[1]){
                    merged.back()[1] = max(merged.back()[1] , intervals[i][1]);
                }else{
                    merged.push_back(intervals[i]);
                }
            }
            return merged;
        }
};