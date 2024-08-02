#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_occupied_diagonals(int n, int k) {
    if (k == 0) return 0;
    
    vector<int> diagonals;
    for (int i = 1; i <= n; ++i) {
        diagonals.push_back(i);
        if (i < n) diagonals.push_back(i);
    }
    
    sort(diagonals.begin(), diagonals.end(), greater<int>());
    
    int count = 0;
    for (int diagonal : diagonals) {
        if (k <= 0) break;
        k -= diagonal;
        count++;
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << min_occupied_diagonals(n, k) << endl;
    }
    
    return 0;
}