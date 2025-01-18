#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
class Solution{
public:
    vector<int> replaceWithRank(vector<int> &arr, int N){
        set<int> s(arr.begin(), arr.end());
        map<int, int>  mp;
        int level = 0;
        for (int x : s){
            mp[x] = ++level;
        };
        vector<int> ans(N);
        for(int  i =0  ; i < N ; i++ ){
            ans[i] = mp[arr[i]];
        }
        return ans;
    }
};