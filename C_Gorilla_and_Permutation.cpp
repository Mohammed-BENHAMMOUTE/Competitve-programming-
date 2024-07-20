#include <iostream>
#include <vector>

using namespace std;

void solve(int n, int m, int k) {
    vector<int> result;

    // Push all numbers from n to k in descending order to maximize f(i)
    for (int i = n; i >= k; --i) {
        result.push_back(i);
    }

    // Push all numbers from k-1 to m+1 in descending order (neutral elements)
    for (int i = k - 1; i > m; --i) {
        result.push_back(i);
    }

    // Push all numbers from 1 to m in increasing order to minimize g(i)
    for (int i = 1; i <= m; ++i) {
        result.push_back(i);
    }

    // Output the result
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        solve(n, m, k);
    }

    return 0;
}
