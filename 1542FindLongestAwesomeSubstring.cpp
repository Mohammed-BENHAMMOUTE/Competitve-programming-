#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        unordered_map<int, int> seen;
        int mask = 0;
        seen[0] = -1;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int digit = s[i] - '0';
            mask ^= (1 << digit);
            if(seen.find(mask) != seen.end())
            {
                ans = max(ans, i - seen[mask]);
            };

            for(int d = 0 ; d <= 9 ; d++){
                int newMask = mask ^ (1 << d);
                if(seen.find(newMask) != seen.end())
                {
                    ans = max (ans, i - seen[newMask]);
                }
            }
            if(seen.find(mask) == seen.end())
            {
                seen[mask] = i;
            }
        };
        return ans;
    }
};