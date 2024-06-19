#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int countDistinctPositions(int x, int y, int z, long long k) {
    int max_positions = 0;
    for (int a = 1; a <= cbrt(k); ++a) {
        if (k % a == 0) {
            long long remaining_volume = k / a;
            for (int b = 1; b <= sqrt(remaining_volume); ++b) {
                if (remaining_volume % b == 0) {
                    int c = remaining_volume / b;
                    if (a <= x && b <= y && c <= z) {
                        max_positions = max(max_positions, (x - a + 1) * (y - b + 1) * (z - c + 1));
                    }
                    if (a <= x && c <= y && b <= z) {
                        max_positions = max(max_positions, (x - a + 1) * (y - c + 1) * (z - b + 1));
                    }
                    if (b <= x && a <= y && c <= z) {
                        max_positions = max(max_positions, (x - b + 1) * (y - a + 1) * (z - c + 1));
                    }
                    if (b <= x && c <= y && a <= z) {
                        max_positions = max(max_positions, (x - b + 1) * (y - c + 1) * (z - a + 1));
                    }
                    if (c <= x && a <= y && b <= z) {
                        max_positions = max(max_positions, (x - c + 1) * (y - a + 1) * (z - b + 1));
                    }
                    if (c <= x && b <= y && a <= z) {
                        max_positions = max(max_positions, (x - c + 1) * (y - b + 1) * (z - a + 1));
                    }
                }
            }
        }
    }
    return max_positions;
}

int main() {
    int t;
    cin >> t;
    vector<int> results(t);
    
    for (int i = 0; i < t; ++i) {
        int x, y, z;
        long long k;
        cin >> x >> y >> z >> k;
        results[i] = countDistinctPositions(x, y, z, k);
    }
    
    for (int result : results) {
        cout << result << endl;
    }
    
    return 0;
}
