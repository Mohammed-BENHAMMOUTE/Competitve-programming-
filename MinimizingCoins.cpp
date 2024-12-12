//
// Created by mohammed on 10/12/24.
//

// #include "MinimizingCoins.h"
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    int nums[n];
    int tot = 0;
    for (int i = 0; i < n ; i++) {
        cin >> nums[i]; tot+=nums[i];
    }
    vector<int> dp(x+1, INT_MAX);
    dp[0] =0;
// do we need the total sum ? no ?
    for (int i = 0; i < n ;i++) {
        for (int k = nums[i]; k <= x ;k++) {
            if (dp[k-nums[i]] != INT_MAX) {
                dp[k] = min (dp[k], dp[k-nums[i]] +1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x])<< endl;
}

