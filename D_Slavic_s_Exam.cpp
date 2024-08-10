#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int i = 0, j = 0;
    
    // Iterate through s
    while (i < s.length()) {
        if (j < t.length()) {
            if (s[i] == '?') {
                s[i] = t[j];
                j++;
            } else if (s[i] == t[j]) {
                j++;
            }
        } else if (s[i] == '?') {
            s[i] = 'a';
        }
        i++;
    };
    
    if (j == t.length()) {
        cout << "YES\n" << s << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    
    while (testCases--) {
        solve();
    }
    
    return 0;
}