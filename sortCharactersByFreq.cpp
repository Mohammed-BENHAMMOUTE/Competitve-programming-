#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        for (char x : s) {
            m[x]++;
        }
        vector<pair<int, char>> preq;
        for (auto p : m) {
            preq.push_back({p.second, p.first});
        }
        sort(preq.rbegin(), preq.rend());
        string ans;
        for (const auto& x : preq) {
            ans.append(x.first, x.second);
        }
        return ans;
    }
};
