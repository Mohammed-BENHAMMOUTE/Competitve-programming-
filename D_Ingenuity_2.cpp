#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void solveSingleCase(int n, const string& s) {
    vector<pair<int, int>> prefixSum(n + 1, {0, 0});
    unordered_map<int, int> coordinateMap;

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i];
        if (s[i] == 'N') prefixSum[i + 1].second += 1;
        else if (s[i] == 'S') prefixSum[i + 1].second -= 1;
        else if (s[i] == 'E') prefixSum[i + 1].first += 1;
        else if (s[i] == 'W') prefixSum[i + 1].first -= 1;
    }

    // Try to find a point to split the instructions
    for (int i = 1; i <= n; ++i) {
        int combined = prefixSum[i].first * 200001 + prefixSum[i].second;
        if (coordinateMap.find(combined) != coordinateMap.end()) {
            int j = coordinateMap[combined];
            if (j > 0) {
                string result(n, 'R');
                for (int k = j; k < i; ++k) {
                    result[k] = 'H';
                }
                cout << result << '\n';
                return;
            }
        }
        coordinateMap[combined] = i;
    }

    cout << "NO\n";
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        solveSingleCase(n, s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
