#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long max_petals(vector<int>& flowers, long long m) {
    sort(flowers.begin(), flowers.end());
    
    long long max_sum = 0;
    long long current_sum = 0;
    int left = 0;
    int n = flowers.size();
    
    for (int right = 0; right < n; right++) {
        // Check if taking just this flower is better
        if (flowers[right] <= m) {
            max_sum = max(max_sum, (long long)flowers[right]);
        }
        
        while (left < right && flowers[right] - flowers[left] > 1) {
            current_sum -= flowers[left];
            left++;
        }
        
        current_sum += flowers[right];
        
        if (current_sum <= m) {
            max_sum = max(max_sum, current_sum);
        } else {
            while (left <= right && current_sum > m) {
                current_sum -= flowers[left];
                left++;
            }
            if (current_sum <= m) {
                max_sum = max(max_sum, current_sum);
            }
        }
    }
    
    return max_sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;
        
        vector<int> flowers(n);
        for (int i = 0; i < n; i++) {
            cin >> flowers[i];
        }
        
        cout << max_petals(flowers, m) << endl;
    }
    
    return 0;
}