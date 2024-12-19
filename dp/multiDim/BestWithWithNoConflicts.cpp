#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int maxAge = *max_element(ages.begin(), ages.end());
        vector<pair<int,int>> vec;
        for(int i =0 ; i < n ; i++){
            vec.push_back(make_pair(ages[i], scores[i]));
        }
        sort(vec.begin(), vec.end());
        int maxElement = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            dp[i] = vec[i].second;
            for(int k = 0; k < i; k++){
                if(vec[k].second <= vec[i].second) {
                    dp[i] = max(dp[i], dp[k] + vec[i].second);
                }
            }
            maxElement = max(maxElement, dp[i]);
        }
        return maxElement;
    }
};