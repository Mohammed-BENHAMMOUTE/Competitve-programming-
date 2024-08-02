#include <iostream>
#include <vector>

using namespace std;

vector<int> solve_test_case() {
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    
    vector<int> a(n, 0);
    
    a[0] = b[0];
    
    for (int i = 1; i < n - 1; i++) {
        a[i] = b[i-1] | b[i];
    }
    
    a[n-1] = b[n-2];
    
    for (int i = 0; i < n - 1; i++) {
        if ((a[i] & a[i+1]) != b[i]) {
             return{-1};
        };
    }
    
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        vector<int> result = solve_test_case();
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i < result.size() - 1 ? " " : "\n");
        }
    }
    
    return 0;
};
