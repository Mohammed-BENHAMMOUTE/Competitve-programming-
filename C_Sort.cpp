#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int ALPHABET_SIZE = 26;

void solve_case() {
    int n, q;
    std::cin >> n >> q;
    
    std::string a, b;
    std::cin >> a >> b;
    
    // Precompute cumulative frequency for each character
    std::vector<std::vector<int>> freq_a(n + 1, std::vector<int>(ALPHABET_SIZE, 0));
    std::vector<std::vector<int>> freq_b(n + 1, std::vector<int>(ALPHABET_SIZE, 0));
    
    for (int i = 0; i < n; ++i) {
        freq_a[i + 1] = freq_a[i];
        freq_b[i + 1] = freq_b[i];
        freq_a[i + 1][a[i] - 'a']++;
        freq_b[i + 1][b[i] - 'a']++;
    }
    
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--; // Convert to 0-based index
        
        int diff = 0;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            int count_a = freq_a[r][i] - freq_a[l][i];
            int count_b = freq_b[r][i] - freq_b[l][i];
            diff += std::abs(count_a - count_b);
        }
        
        std::cout << diff / 2 << std::endl;
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