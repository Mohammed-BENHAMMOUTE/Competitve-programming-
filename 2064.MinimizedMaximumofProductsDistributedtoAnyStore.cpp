#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"

using namespace std;



class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int mx = *max_element(quantities.begin(), quantities.end());
        int l = 1, r = mx+1;   
        while(l < r) {
            int mid = l + (r-l +1)/2;
            if(valid(mid, quantities , n)){
                r = mid;
            }else{
                l = mid +1;
            }
        };
        return l;
    }

    bool valid(int target , vector<int>& arr, int n) {
        int tot = 0 ;
        for(const int& x : arr){
            tot +=ceil(x/target);
        };
        return tot <= n;
    }
};



int main()
{
    fastio;
    // code goes here
    return 0;
}