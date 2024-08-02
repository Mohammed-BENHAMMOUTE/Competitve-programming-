#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findTime(int d, const vector<int>& a, const vector<int>& b) {
    auto it = lower_bound(a.begin(), a.end(), d);
    if (it != a.end() && *it == d) {
        return b[it - a.begin()];
    }
    
    int i = it - a.begin() - 1;
    if (i == -1) return 0;
    double time = b[i] + (double)(d - a[i]) * (b[i+1] - b[i]) / (a[i+1] - a[i]);
    return floor(time);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;
        
        vector<int> a(k+1), b(k+1);
        a[0] = b[0] = 0;
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];
        
        while (q--) {
            int d;
            cin >> d;
            cout << findTime(d, a, b) << " ";
        }
        cout << endl;
    }
    return 0;
}