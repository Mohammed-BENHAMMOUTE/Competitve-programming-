#include<bits/stdc++.h>
#define endl "\n"
const int MAX = 1e5+1;
const int MOD = 100000;
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(MOD+1, INT_MAX);
        queue<pair<int,int>> q;
        q.push({start, 0});
        dist[start] = 0;
        
        while(!q.empty()) {
            auto node = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(steps > dist[node]) continue;
            
            for(int x : arr) {
                long long curr = (x * node) % MOD;
                if(steps + 1 < dist[curr]) {
                    dist[curr] = steps + 1;
                    if(curr == end) return steps + 1;
                    q.push({curr, steps + 1});
                }
            }
        }
        return -1;
    }
};