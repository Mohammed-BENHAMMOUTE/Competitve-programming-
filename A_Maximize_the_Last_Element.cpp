#include <iostream>
#include <vector>
#include <algorithm>

int solve_test_case() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    
    for(int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    
    int max_val = a[0];
    for(int i = 2; i < n; i += 2) {
        max_val = std::max(max_val, a[i]);
    }
    
    return max_val;
}

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; ++i) {
        int result = solve_test_case();
        std::cout << result << std::endl;
    }
    
    return 0;
}
