#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<long long> solve(std::vector<long long>& a) {
    std::vector<long long> operations;
    while (std::set<long long>(a.begin(), a.end()).size() > 1 && operations.size() < 40) {
        long long min_val = *std::min_element(a.begin(), a.end());
        long long max_val = *std::max_element(a.begin(), a.end());
        long long x = (min_val + max_val) / 2;
        operations.push_back(x);
        for (auto& val : a) {
            val = std::abs(val - x);
        }
    }
    
    if (std::set<long long>(a.begin(), a.end()).size() == 1 && a[0] != 0) {
        operations.push_back(a[0]);
        std::fill(a.begin(), a.end(), 0);
    }
    
    if (std::all_of(a.begin(), a.end(), [](long long val) { return val == 0; })) {
        return operations;
    }
    return {};
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::vector<long long> operations = solve(a);
        if (operations.empty()) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << operations.size() << std::endl;
            if (!operations.empty()) {
                for (size_t i = 0; i < operations.size(); i++) {
                    std::cout << operations[i] << (i < operations.size() - 1 ? " " : "");
                }
                std::cout << std::endl;
            } else {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}