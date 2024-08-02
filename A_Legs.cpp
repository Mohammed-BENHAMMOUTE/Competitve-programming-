#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    
    std::vector<int> results;
    
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        int min_animals = (n % 4 == 0) ? n / 4 : n / 4 + 1;
        
        results.push_back(min_animals);
    }
    
    for (int result : results) {
        std::cout << result << std::endl;
    }
    
    return 0;
}