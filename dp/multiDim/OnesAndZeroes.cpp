#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        vector<pair<int,int>> vec;
        for(int i = 0; i < size; i++){
            int count0 = 0;
            int count1 = 0;
            for(const char& x : strs[i]){
                if(x == '0'){
                    count0++;
                }else{
                    count1++;
                }
            }
            vec.push_back({count0, count1});
        };
        for(int i = 1; i <= size; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++) {  // Changed l to k and fixed bound to n
                    dp[i][j][k] = dp[i-1][j][k];
                    int zeroes = vec[i-1].first;
                    int ones = vec[i-1].second;

                    if(j >= zeroes && k >= ones){
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-zeroes][k-ones] + 1);
                    }
                }
            }
        };
        return dp[size][m][n];
    }
};