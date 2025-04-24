#include <bits/stdc++.h>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll ;

class Solution {
public:
  int scoreOfParenthesis(string s) {
    int n = s.size();
    stack<pair<char , int>> st;
    int countOpen = 0;
    int i =0 ;
    ll ans = 0;
    for(auto& x : s)
    {
      if(x == '(')
      {
        countOpen++;
        st.push({x, i});
      }else{
         int diff =  i - st.top().second;
        st.pop();
        countOpen--;
        if(diff == 1){
          ans += pow(2, countOpen);
        }
      }
      i++;
    }
    return ans;
  }
}
