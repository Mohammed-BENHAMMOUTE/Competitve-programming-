#include <bits/stdc++.h>
class Solution{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
        int n = books.size();
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++){
            int thick = books[i-1][0];
            int height = books[i-1][1];
            dp[i] = dp[i-1] + height;
            for(int j = i-1; j > 0 && thick < shelfWidth; j--){
                height = max(height, books[j-1][1]);
                if(thick + books[j-1][0] > shelfWidth){
                    break;
                }
                thick += books[j-1][0];
                dp[i] = min(dp[j-1] + height, dp[i]);
            }
        }
        return dp[n];
    }
};