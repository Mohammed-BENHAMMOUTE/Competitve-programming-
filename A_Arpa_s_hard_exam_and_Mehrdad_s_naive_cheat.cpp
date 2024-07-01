#include <iostream>

int main() {
    // Read the input
    unsigned int n;
    std::cin >> n;
    
    if (n == 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    
    int last_digits[] = {6, 8, 4, 2};
    
    int result = last_digits[n % 4];
    
    std::cout << result << std::endl;
    
    return 0;
}