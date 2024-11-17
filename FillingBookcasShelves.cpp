using namespace std;
#include<vector>
//Mohammed Benhammoute
//12:22:07
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
      int n = nums.size();  
      vector<vector<int>>  dp(n, vector<int>(2, 0));
      dp[0] = books[0];
      for(int i =1 ; i < n ; i++){
        if(books[1] + dp[i-1][1] > shelfWidth){
          dp[i] = {books[i][0],books[i][1] + dp[i-1][1]};
        }else{
          dp[i][0] = dp[i-1][0]+ books[0];
          dp[i][1] = max(dp[i-1][1],books[1]);
        };
      };
      return dp[n-1][1];
    };
};
