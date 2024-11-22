#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums;
    
    // Get numbers and process remainders
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        nums.push_back(((x%k)+k)%k);
    }
    
    // dp[i][j] = can we get remainder j using first i numbers?
    vector<vector<bool>> dp(n, vector<bool>(k, false));
    dp[0][nums[0]] = true;  // Base case: first number's remainder
    
    // For each number
    for(int i = 1; i < n; i++) {
        // For each possible remainder
        for(int j = 0; j < k; j++) {
            if(dp[i-1][j]) {
                // If we can get remainder j using first i-1 numbers
                // We can get two new remainders by adding/subtracting current number
                int add = ((j + nums[i]) % k + k) % k;
                int sub = ((j - nums[i]) % k + k) % k;
                dp[i][add] = true;
                dp[i][sub] = true;
            }
        }
    }
    
    cout << (dp[n-1][0] ? "Divisible\n" : "Not divisible\n");
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}