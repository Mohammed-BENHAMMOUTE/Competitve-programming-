#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;
  ll r; cin >> r;
  vector<ll> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  
  ll ans = 0;
  for (int i = 0; i < n-1; i++) {
    // Find first monument with distance > r from monument i
    auto it = upper_bound(a.begin() + i + 1, a.end(), a[i] + r);
    // Count all valid monuments (those with distance > r)
    ans += (a.end() - it);
  }
  
  cout << ans << endl;
  return 0;
}
 