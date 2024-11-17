using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int n = days.size();
       vector<int> dp(n+2, 0);
       dp[n] = min({costs[0], costs[1], costs[2]});
       set<int> s(days.begin(), days.end());
       for(int i = n-1; i>= 1; i--){
         if(s.find(i) != s.end()){
            dp[i] = dp[i+1];
         }else{
            dp[i] = min({dp[i+1] + costs[0], dp[(i+7)%(n+2)]+ costs[1], dp[(i+30)]+costs[2]});
                     
         }
       }
       return dp[1];
    }
}; 
