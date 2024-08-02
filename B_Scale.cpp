#include <iostream>
#include <vector>
#include <string>

void solve_case() {
    int n, k;
    std::cin >> n >> k;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    int reduced_size = n / k;
    for (int i = 0; i < reduced_size; ++i) {
        for (int j = 0; j < reduced_size; ++j) {
            std::cout << grid[i * k][j * k];
        }
        std::cout << std::endl;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        solve_case();
    }

    return 0;
}