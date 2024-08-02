#include <iostream>
#include <vector>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> color(n + 1);
    int max_color;

    if (n == 1) {
        max_color = 1;
        color[1] = 1;
    } else if (n <= 3) {
        max_color = 2;
        color[1] = 1;
        color[2] = 2;
        if (n == 3) color[3] = 2;
    } else if (n <= 5) {
        max_color = 3;
        color[1] = 1;
        color[2] = 2;
        color[3] = 2;
        color[4] = 3;
        if (n == 5) color[5] = 3;
    } else {
        max_color = 4;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                color[i] = (i % 4 == 1) ? 1 : 2;
            } else {
                color[i] = (i % 4 == 0) ? 3 : 4;
            }
        }
    }

    std::cout << max_color << "\n";
    for (int i = 1; i <= n; i++) {
        std::cout << color[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
