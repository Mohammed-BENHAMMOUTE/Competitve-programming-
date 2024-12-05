    #include <vector>
    #include <algorithm>
    #include <map>
#include <climits>
    
    using namespace std;
    
class Solution {
    public:
        vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
            vector<pair<int, int>> nums;
            vector<int> ans;
            sort(items.begin(), items.end());
            
            int mx = 0;
            for(const auto& item : items) {
                mx = max(mx, item[1]);
                nums.push_back({item[0], mx});
            }
            
            for(int x : queries) {
                auto it = upper_bound(nums.begin(), nums.end(), make_pair(x, INT_MAX));
                if(it == nums.begin()) {
                    ans.push_back(0);
                } else {
                    --it;
                    ans.push_back(it->second);
                }
            }
            
            return ans;
        }
};