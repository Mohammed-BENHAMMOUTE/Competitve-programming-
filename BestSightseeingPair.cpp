#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> prefixe(n, 0);
        vector<int> suffixe(n, 0);
        prefixe[0] = values[0];
        suffixe[n-1] = values[n-1] - (n-1); 
        for(int i =1 ; i < n ; i++) {
            prefixe[i] = max(values[i] + i, prefixe[i-1]);
        };
        for(int i =n-2; i >= 0 ; i--) {
            suffixe[i] = max(values[i] - i, suffixe[i+1]);
        };

        int res = 0;
        for(int i =0 ; i < n ; i++){
            res = max(prefixe[i], suffixe[i+1]);
        };
        return res;

    }
};