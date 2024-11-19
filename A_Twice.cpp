#include <iostream>
#include <map>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    if (n == 1) {
        int x; cin >>x;
        cout << 0 << endl;
        return;
    }
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        m[x]++;
    }
    // for 
    // (auto it = m.begin(); it != m.end(); ++it) {
    //     cout << it->first << " : " << it->second << endl;
    // }
    int ans = 0;
    for (auto x : m) {
        
        ans += x.second / 2;
        // cout <<ans<<" ";
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}