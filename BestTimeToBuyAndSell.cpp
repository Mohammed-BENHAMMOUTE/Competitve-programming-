#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> bestTimeToSell(n, 0);
        bestTimeToSell[n-1] = prices[n-1];

        for(int i = n-2;i>= 0; i++){ 
           bestTimeToSell[i] = max(prices[i], bestTimeToSell[i+1]);
        }

        int maxProfitSum = 0;
        for(int i =0; i < n-1; i++){
            maxProfitSum = max(maxProfitSum,bestTimeToSell[i+1] - prices[i]);
        }
        return maxProfitSum;
    }
};