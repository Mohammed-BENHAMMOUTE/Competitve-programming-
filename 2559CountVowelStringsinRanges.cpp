#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(const vector<string>& words, const vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + (checkVowel(words[i]) ? 1 : 0);
        }
        vector<int> ans;
        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            int res = pre[r + 1] - pre[l];
            ans.push_back(res);
        }
        return ans;
    }

private:
    bool checkVowel(const string& s) {
        static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        return vowels.count(s.front()) && vowels.count(s.back());
    }
};