#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> ones(n+1, 0);
        vector<int> zeroes(n+1,0);

        for(int  i =0; i < n; i++){
            zeroes[i+1] = zeroes[i] + (s[i] == '0' ? 1 : 0);
        }
        for(int j = n-1; j >= 0; j--){
            ones[j] = ones[j+1] + (s[j] == '1' ? 1 : 0);
        }
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            ans = max(ans, zeroes[i] + ones[i]);
        }
        return ans;
    }
}; 