#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> x(n); for (int& val : x) cin >> val;
    int m; cin >> m; vector<int> y(m); for (int& val : y) cin >> val;
    int k; cin >> k; vector<int> z(k); for (int& val : z) cin >> val;
    int A, B; cin >> A >> B;

    // Find the required values
    double maxR1 = *max_element(x.begin(), x.end());
    double maxP1 = *max_element(y.begin(), y.end());
    double minP2 = *min_element(z.begin(), z.end());

    double numerator = maxR1 * maxR1 * B * maxP1;
    double denominator = B * maxP1 + A * minP2;
    double r2 = sqrt(numerator / denominator);

    cout << fixed << setprecision(12) << r2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
