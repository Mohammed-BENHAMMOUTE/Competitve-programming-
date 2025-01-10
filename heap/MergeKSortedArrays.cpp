#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"


// here you are asked to merge k sorted array.

using namespace std;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        int n = arr.size();
        priority_queue<int> pq;
        for(int i = 0; i < n ; i++){
            for(int x : arr[i]){
                pq.push(x);
            }
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};