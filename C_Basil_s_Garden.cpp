#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int seconds = 0;
    int prev_height = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (h[i] <= prev_height) {
            prev_height = max(0, prev_height - 1);
        } else {
            seconds += h[i] - prev_height;
            prev_height = h[i] - 1;
        }
    }

    cout << seconds << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}