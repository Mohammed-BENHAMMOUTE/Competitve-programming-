#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        for (const auto& building : buildings) {
            events.emplace_back(building[0], -building[2]);
            events.emplace_back(building[1], building[2]);
        }
        sort(events.begin(), events.end());

        priority_queue<int> heights;
        heights.push(0); // Initial ground level
        unordered_map<int, int> heightCount;
        int prevMaxHeight = 0;
        vector<vector<int>> result;

        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) { // start of a building
                heights.push(-h);
                heightCount[-h]++;
            } else { // end of a building
                heightCount[h]--;
                if (heightCount[h] == 0) {
                    heightCount.erase(h);
                }
            }

            while (!heights.empty() && heightCount[heights.top()] == 0) {
                heights.pop();
            }

            int currentMaxHeight = heights.top();
            if (currentMaxHeight != prevMaxHeight) {
                result.push_back({x, currentMaxHeight});
                prevMaxHeight = currentMaxHeight;
            }
        }

        // Ensure the final ground level point is added
        if (!result.empty() && result.back()[1] != 0) {
            result.push_back({events.back().first, 0});
        }

        return result;
    }
};