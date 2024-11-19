#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n && k > 0; i++) {
        if (a[i] < 0) {
            a[i] = -a[i];
            k--;
        }
    }

    if (k % 2 == 1) {
        sort(a.begin(), a.end());
        a[0] = -a[0];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i];
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}