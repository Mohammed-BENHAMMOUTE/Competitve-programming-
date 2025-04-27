#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                pal[i][j] = isPalindrome(s, i, j);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (pal[0][i]) {
                dp[i] = 0;
            } else {
                dp[i] = i; // Worst case: cut at each character
                for (int j = 0; j < i; ++j) {
                    if (pal[j + 1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};
