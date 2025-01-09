#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    multiset<int> prices;
    
    // Read ticket prices
    for(int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.insert(price);
    }
    
    // Process each customer
    for(int i = 0; i < m; i++) {
        int maxPrice;
        cin >> maxPrice;
        
        auto it = prices.upper_bound(maxPrice);
        if(it != prices.begin()) {
            --it;
            if(*it <= maxPrice) {
                cout << *it << endl;
                prices.erase(it);
                continue;
            }
        }
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}