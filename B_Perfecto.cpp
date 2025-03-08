#include <bits/stdc++.h>
using namespace std;

void generate_perfect_permutation(int n) {
    vector<int> perm(n + 1, 0); // To store the permutation
    int start = 1, end = n;

    while (end >= start) {
        if (end == start) {
            perm[start] = end; // Place the last number if odd count
            break;
        }
        perm[start] = end;
        perm[start + 1] = end - 1;
        start += 2;
        end -= 2;
    }

    for (int i = 1; i <= n; i++) {
        cout << perm[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "-1\n";  // Impossible case
        } else {
            generate_perfect_permutation(n);
        }
    }

    return 0;
}
