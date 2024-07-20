#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeBananas(int a, int b, int c) {
    for (int i = 0; i < 5; ++i) {
        if (a <= b && a <= c) {
            ++a;
        } else if (b <= a && b <= c) {
            ++b;
        } else {
            ++c;
        }
    }
    return a * b * c;
}

int main() {
    int t;
    cin >> t;
    vector<int> results;

    for (int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        results.push_back(maximizeBananas(a, b, c));
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
