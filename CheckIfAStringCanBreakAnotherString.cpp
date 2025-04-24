#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkIfCanBreak(string s1 , string s2)
  {
    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());

    int n = s1.size();
    int temp = 0;
    while(temp < n && s1[temp] == s2[temp])
    {
      temp++;
    }
    if(temp < n){
      if(s2[temp] < s1[temp]){
        swap(s2 , s1);
      }
    }
    for(int i =0 ; i < n ; i++) {
      if(s2[i] < s1[i])
      {
        return false;
      }
    }
    return true;
  }
};
