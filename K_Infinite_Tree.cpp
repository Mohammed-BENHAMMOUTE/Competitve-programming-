#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;

    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        long long depth_a = log(a) / log(k) + 1; // Depth of node a
        long long depth_b = log(b) / log(k) + 1; // Depth of node b

        // Make both nodes at the same depth
        while (depth_a > depth_b) {
            a = (a - 2) / k + 1; // Move a closer to the root
            depth_a--;
        }
        while (depth_b > depth_a) {
            b = (b - 2) / k + 1; // Move b closer to the root
            depth_b--;
        }

        // Find the common ancestor
        while (a != b) {
            a = (a - 2) / k + 1; // Move a closer to the root
            b = (b - 2) / k + 1; // Move b closer to the root
        }

        // Length of the cycle is the sum of the distances from each node to the common ancestor, plus 1 for the edge connecting the common ancestor to one of the nodes
        long long cycle_length = depth_a + depth_b - 2 * (log(a) / log(k)) + 1;
        cout << cycle_length << endl;
    }

    return 0;
}
