#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;
int subarrayXor(vector<int>& A, int B) {
    int n = A.size();
    int count = 0;
    int xor_so_far = 0;

    unordered_map<int,int> cnt;
    cnt[0] = 1;
    for(int i =0 ; i < n ; i++) {
        xor_so_far^=A[i];
        int target = xor_so_far^B;
        count += cnt[target];
        cnt[xor_so_far]++;
    }
    return count;
}