#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(long long dividend, int divisor) {
        // Handle edge cases for divisor == 1 or -1
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        // Determine the sign of the result
        int sdiv = (divisor < 0 ? -1 : 1);
        int sdid = (dividend < 0 ? -1 : 1);

        // Convert to positive for binary search
        long long divid = abs((long long)dividend);
        long long divis = abs((long long)divisor);

        // If divisor is greater, quotient is 0
        if (divid < divis) return 0;

        long long l = 0;
        long long r = divid; // Upper bound for binary search
        long long ans = 0;

        // Binary search for the quotient
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid * divis <= divid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // Apply the sign and constrain to INT range
        long long result = sdiv * sdid * ans;
        if (result < INT_MIN) return INT_MIN;
        if (result > INT_MAX) return INT_MAX;
        return result;
    }
};
