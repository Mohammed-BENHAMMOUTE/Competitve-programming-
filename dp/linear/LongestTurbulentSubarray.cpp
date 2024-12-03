#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return n;
        int res = 1;
        int dp = 1;
        int prevsigne = 0;
        for(int i = 1; i < n; i++){
            int signe = (arr[i] - arr[i-1]) > 0 ? 1 : (arr[i] - arr[i-1]) < 0 ? -1 : 0;
            if (signe == 0) {
                dp = 1;
            } else if (signe * prevsigne == -1) {
                dp++;
            } else {
                dp = 2;
            }
            res = max(res, dp);
            prevsigne = signe;
        }
        return res;
    }
};