#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int oo = 1e6 + 5;
const vector<pi> moves = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

bool isValidMove(int x, int y) {
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

vvi knightAdjacency() {
    vvi adj(64);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (const auto& move : moves) {
                int x = i + move.first, y = j + move.second;
                if (isValidMove(x, y)) {
                    adj[i * 8 + j].push_back(x * 8 + y);
                }
            }
        }
    }
    return adj;
}

int bfs(int s, int d, vvi& adj) {
    vi len(64, oo);
    queue<int> q;
    q.push(s);
    len[s] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int neighbor : adj[cur]) {
            if (len[neighbor] == oo) {
                len[neighbor] = len[cur] + 1;
                if (neighbor == d) {
                    return len[neighbor];
                }
                q.push(neighbor);
            }
        }
    }
    return oo; // Should never reach here if d is always reachable
}

void solve(const string& s1, const string& s2, vvi& adj) {
    if (s1 == s2) {
        cout << "To get from " << s1 << " to " << s2 << " takes 0 knight moves.\n";
        return;
    }
    int x1 = s1[0] - 'a', y1 = s1[1] - '1';
    int x2 = s2[0] - 'a', y2 = s2[1] - '1';
    int moves = bfs(x1 * 8 + y1, x2 * 8 + y2, adj);
    cout << "To get from " << s1 << " to " << s2 << " takes " << moves << " knight moves.\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi adj = knightAdjacency();
    string s1, s2;
    while (cin >> s1 >> s2) {
        solve(s1, s2, adj);
    }

    return 0;
}
