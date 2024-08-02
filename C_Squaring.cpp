#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int makeNonDecreasing(vector<int>& a) {
    int n = a.size();
    int operations = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[i+1]) {
            if (a[i+1] == 1) {
                operations++;
                a[i+1] = 1;  // Square of 1 is still 1
            } else if (a[i+1] <= 3 && a[i] > 9) {
                return -1;  // Impossible case
            } else {
                int target = a[i];
                int current = a[i+1];
                int count = 0;
                
                while (current < target) {
                    if ((long long)current * current > 1000000) {
                        return -1;  // Exceeds maximum possible value
                    }
                    current *= current;
                    count++;
                }
                
                operations += count;
                a[i+1] = current;
            }
        }
    }
    
    return operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << makeNonDecreasing(a) << '\n';
    }
    
    return 0;
}