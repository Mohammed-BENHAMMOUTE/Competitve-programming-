#include <bits/stdc++.h>
#include <vector>
using namespace std;


// we need to check if we can make k palindromes with all the characters of s;
// what is the condition to make sure that we can with the characters of s 
// we can make k palindromes.

// if the number of odd counts if more than 
//


class Solution {
public:
  bool canConstruct(string s, int k) {
    int n = s.size();
    if(n < k){
      return false;
    }
    int count[26] = {0};
    for(const char& x : s){
      count[x-'a']++;
    }
    int odds = 0;
    for(int i =0 ; i < 26 ; i++)
    {
      if(count[i]%2 == 1)
      {
        odds++;
      }
    }
    if(odds > k){
      return false;
    }
    return true;
  }
};
