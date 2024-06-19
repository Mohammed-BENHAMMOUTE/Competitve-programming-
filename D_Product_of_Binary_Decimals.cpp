#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

vector<int> bin;

// Function to generate all binary decimals up to 100000
void generateBinaryDecimals() {
    for (int i = 1; i <= 100000; ++i) {
        string s = to_string(i);
        bool isBinaryDecimal = true;
        for (char c : s) {
            if (c != '0' && c != '1') {
                isBinaryDecimal = false;
                break;
            }
        }
        if (isBinaryDecimal) {
            bin.push_back(i);
        }
    }
}

bool canBeProductOfBinaryDecimals(int n) {
    if (n == 1) return true;
    
    queue<int> q;
    unordered_set<int> visited;
    q.push(1);
    visited.insert(1);
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        for (int b : bin) {
            int next = current * b;
            if (next == n) return true;
            if (next > n) break;
            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                q.push(next);
            }
        }
    }
    
    return false;
}

void solve() {
    int n; 
    cin >> n;
    if (canBeProductOfBinaryDecimals(n)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    generateBinaryDecimals();
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}