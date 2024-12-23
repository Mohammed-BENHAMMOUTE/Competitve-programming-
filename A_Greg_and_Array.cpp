#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<array<int, 3>> ops(m);
    for(int i = 0; i < m; i++) {
        cin >> ops[i][0] >> ops[i][1] >> ops[i][2];
        ops[i][0]--; ops[i][1]--;  
    }
    
    vector<ll> freq(m + 1, 0);  
    for(int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;  
        freq[l]++;
        freq[r + 1]--;
    }
    
    vector<ll> actual(m, 0);
    ll curr = 0;
    for(int i = 0; i < m; i++) {
        curr += freq[i];
        actual[i] = curr;
    }
    
    vector<ll> diff(n + 1, 0);
    for(int i = 0; i < m; i++) {
        if(actual[i] > 0) {
            int l = ops[i][0], r = ops[i][1];
            ll val = ops[i][2] * actual[i];
            diff[l] += val;
            diff[r + 1] -= val;
        }
    }
    
    curr = 0;
    for(int i = 0; i < n; i++) {
        curr += diff[i];
        cout << arr[i] + curr << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}