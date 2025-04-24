#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int minChangesToPalindrome(const string s , int start , int end){
    int changes = 0;
    while (start < end){
      if(s[start] != s[end])
      {
        changes++;
      }
      start++;
      end--;
    }
    return changes;
  };

  int palindromePartitioning(string s , int k){
    int n = s.size();
    vector<vector<int>> dp(n+1 , vector<int>(k+1 , INT_MAX));
    vector<vector<int>> cost(n , vector<int>(n, 0));
    for(int i =0 ; i < n; i++) {
      for(int j =0 ; j < n ;++j)
      {
        cost[i][j] = minChangesToPalindrome(s, i , j);
      }
    }
    for(int i =0 ; i < n; i++)
    {
      dp[i+1][1] = cost[0][i];
    }

    for(int i = 1 ; i <= n ;i++)
    {
      for(int j = 2 ; j <= min(i, k); j++)
      {
        for(int m = j -1; m < i ; m++)
        {
          if(dp[m][j-1] != INT_MAX)
          {
            dp[i][j] = min(dp[i][j] , dp[m][j-1] + cost[m][i-1]);
          }

        }
      }
    }
    return dp[n][k];
    
  }
};
