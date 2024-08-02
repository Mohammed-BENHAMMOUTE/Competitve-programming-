#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <tuple>

using namespace std;

void solve(int a, int b, int c) {
    queue<tuple<int, int, vector<string>>> q;
    set<pair<int, int>> visited;
    q.push({0, 0, {}});
    visited.insert({0, 0});

    while(!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if(y == c) {
            for(const auto& step : steps) {
                cout << step << '\n';
            }
            cout << "success\n";
            return;
        }

        vector<pair<int, int>> next_states = {
            {a, y}, {x, b}, {0, y}, {x, 0},
            {x - min(x, b - y), y + min(x, b - y)},
            {x + min(y, a - x), y - min(y, a - x)}
        };

        vector<string> actions = {
            "fill A", "fill B", "empty A", "empty B",
            "pour A B", "pour B A"
        };

        for(int i = 0; i < next_states.size(); i++) {
            int nx = next_states[i].first;
            int ny = next_states[i].second;
            if (visited.find({nx, ny}) == visited.end()) {
                visited.insert({nx, ny});
                vector<string> new_steps = steps;
                new_steps.push_back(actions[i]);
                q.push({nx, ny, new_steps});
            }
        }
    }
}

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        solve(a, b, c);
    }
    return 0;
}