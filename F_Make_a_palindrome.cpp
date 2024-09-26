#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    int a, b;
    cin >> s >> a >> b;
    
    int n = s.length();
    int changes = 0;
    
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            changes++;
        }
    };
    cout << changes << endl;
    int cost = changes * b;

    cout << cost << "\n";
    
    return 0;
}