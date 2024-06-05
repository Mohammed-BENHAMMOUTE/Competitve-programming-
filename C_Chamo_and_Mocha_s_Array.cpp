#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

bool isPossibleMedian(vector<ll>& arr, ll x) {
    int n = arr.size();
    
    // Check for subarray of length 3 where x can be median
    for (int i = 0; i <= n - 3; ++i) {
        if ((arr[i] == x && arr[i+1] == x) || (arr[i] == x && arr[i+2] == x) || (arr[i+1] == x && arr[i+2] == x)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> copy = a;
    sort(copy.begin(), copy.end());

    int start = 0;
    int end = n - 1;
    ll ans = 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (isPossibleMedian(a, copy[mid])) {
            ans = copy[mid];  // Update ans if current mid is a valid median
            start = mid + 1;  // Move to the right half to find a potentially larger median
        } else {
            end = mid - 1;  // Move to the left half if current mid is not a valid median
        }
    }

    cout << ans << endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
