#include <bits/stdc++.h>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define endl "\n"
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int x, n; 
    cin >> x >> n;
    set<int> lights = {0, x};
    multiset<int> distances = {x};
    for(int i =0 ; i < n; i++) {
        int light; cin >> light;
        auto it = lights.upper_bound(light);
        auto prev = it;
        prev--;
        distances.erase(distances.find((*it - *prev)));
        distances.insert(light - *prev);
        distances.insert(*it - light);
        lights.insert(light);
        cout << *distances.rbegin() <<  " ";
    }
}

int main() {
    fastIO();
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}