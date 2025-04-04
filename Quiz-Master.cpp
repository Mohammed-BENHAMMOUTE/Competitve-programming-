#include <algorithm>
#include <vector>      
#include <iostream>
#include <cstdio>     
#include <climits>    
#include <ios>         

using namespace std;
typedef long long ll;

const int MAXE = 100005;
vector<vector<int>> devisors(MAXE);
bool precomputed = false;

void precompute_Div() {
    if(precomputed) return;
    for (int d = 1; d < MAXE; d++) {
        for (int multiple = d; multiple < MAXE; multiple += d) {
            devisors[multiple].push_back(d);
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
    // Using size MAXE to cover all divisors up to MAXE-1 (divisor values)
    vector<int> remainder_counts(MAXE, 0);
    ll ans = LLONG_MAX; 

    // Sliding window: move right pointer
    for (int right = 0; right < n; right++) {
        // Add a[right] to the window:
        // For each divisor of a[right], update the count
        for (const int& x : devisors[a[right]]) {
            if (remainder_counts[x] == 0) {
                distinct_count++;
            }
            remainder_counts[x]++;
        }
        
        // Shrink window from left while condition is satisfied:
        // We want the window to have all divisors 1..m present.
        // Here, we assume the condition is "distinct_count == m"
        while (distinct_count == m && left <= right) {
            ans = min(ans, a[right] - a[left]);
            // Remove a[left] from the window:
            for (const int& x : devisors[a[left]]) {
                remainder_counts[x]--;
                if (remainder_counts[x] == 0) {
                    distinct_count--;
                }
            }
            left++;
        }
    }
    
    if (ans == LLONG_MAX) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }
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
