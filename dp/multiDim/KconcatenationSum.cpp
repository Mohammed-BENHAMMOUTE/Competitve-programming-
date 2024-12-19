class Solution {
public:
    const int MOD = 1e9 + 7;
    
    long long kadane(vector<int>& arr, int n) {
        long long currSum = arr[0];
        long long maxSum = arr[0];
        
        for(int i = 1; i < n; i++) {
            currSum = max((long long)arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long sum = 0;
        for(int x : arr) sum += x;
        
        if(k == 1) {
            return kadane(arr, n) % MOD;
        }
        
        vector<int> doubleArr = arr;
        for(int x: arr) doubleArr.push_back(x);
        
        long long kadaneTwo = kadane(doubleArr, 2*n);
        
        if(k == 2) return kadaneTwo % MOD;
        
        long long ans;7
        if(sum > 0) {
            ans = (kadaneTwo + ((k-2) * sum % MOD)) % MOD;
        } else {
            ans = kadaneTwo;
        }
        
        return max(ans % MOD,0);
    }
};