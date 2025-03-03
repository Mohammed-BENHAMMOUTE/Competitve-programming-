#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> findMissingAndRepeating(const std::vector<int>& arr) {
    long long n = arr.size();
    
    // Calculate the expected sum and sum of squares from 1 to n
    long long expectedSum = (n * (n + 1)) / 2;
    long long expectedSumSquares = (n * (n + 1) * (2 * n + 1)) / 6;
    
    // Calculate the actual sum and sum of squares in the array
    long long actualSum = 0;
    long long actualSumSquares = 0;
    
    for (int num : arr) {
        actualSum += num;
        actualSumSquares += (long long)num * num;
    }
    
    // Difference equations
    // missing - repeating = expectedSum - actualSum
    long long diffSum = expectedSum - actualSum;
    
    // missing² - repeating² = expectedSumSquares - actualSumSquares
    // which equals (missing - repeating)(missing + repeating)
    long long diffSumSquares = expectedSumSquares - actualSumSquares;
    
    // missing + repeating
    long long sumMissingAndRepeating = diffSumSquares / diffSum;
    
    // Solving for missing and repeating
    int missing = (diffSum + sumMissingAndRepeating) / 2;
    int repeating = sumMissingAndRepeating - missing;
    
    return {repeating, missing};
}

// int main() {
//     // Test cases
//     std::vector<std::vector<int>> testCases = {
//         {2, 2},
//         {1, 3, 3},
//         {4, 3, 6, 2, 1, 1}
//     };
    
//     for (const auto& arr : testCases) {
//         auto result = findMissingAndRepeating(arr);
//         std::cout << "[" << result.first << ", " << result.second << "]" << std::endl;
//     }
    
//     return 0;
// }