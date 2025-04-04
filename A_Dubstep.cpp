#include <bits/stdc++.h>
#include <cwchar>
using namespace std;
void solve() {
    string str;
    cin >> str;
    string ans;
    for (int i = 0; i < str.size();) {
        if (i + 2 < str.size() && str.substr(i, 3) == "WUB") {
            if (!ans.empty() && ans.back() != ' ') {
                ans += ' ';
            }
            i += 3; 
        } else {
            ans += str[i++];
        }
    }
    cout << ans << endl;
}

int main() {
    int t = 1; 
    while (t--) {
        solve();
    }
    return 0;
}
