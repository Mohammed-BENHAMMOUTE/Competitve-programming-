#include <algorithm>
#include <vector>      
#include <iostream>
#include <cstdio>     
#include <climits>    
#include <ios>         

using namespace std;
typedef long long ll;

const int MAXE = 100005;
vector<vector<int>> divisors(MAXE);
bool precomputed = false;

void precompute_Div() {
    if (precomputed) return;
    // For each number multiple, add its divisor d.
    for (int d = 1; d < MAXE; d++) {
        for (int multiple = d; multiple < MAXE; multiple += d) {
            divisors[multiple].push_back(d);
        }
    }
    precomputed = true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int left = 0;
    int distinct_count = 0;
    // Only need counts for divisors 1..m.
    vector<int> remainder_counts(m+1, 0);
    ll ans = LLONG_MAX;

    for (int right = 0; right < n; right++) {
        // For each divisor of a[right], if it's in [1, m], update its count.
        for (const int &x : divisors[a[right]]) {
            if (x <= m) {
                if (remainder_counts[x] == 0)
                    distinct_count++;
                remainder_counts[x]++;
            }
        }
        
        // While the current window [left, right] contains all divisors 1..m:
        while (distinct_count == m && left <= right) {
            ans = min(ans, a[right] - a[left]);
            // Remove a[left] from the window:
            for (const int &x : divisors[a[left]]) {
                if (x <= m) {
                    remainder_counts[x]--;
                    if (remainder_counts[x] == 0)
                        distinct_count--;
                }
            }
            left++;
        }
    }
    
    if (ans == LLONG_MAX)
        printf("-1\n");
    else
        printf("%lld\n", ans);
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute_Div();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
