#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    
    vector<int> freq_s(26, 0), freq_t(26, 0);

    for(char c : s) freq_s[c - 'a']++;
    for(char c : t) freq_t[c - 'a']++;

    for(int i = 0; i < 26; i++) {
        if(freq_t[i] > freq_s[i]) {
            cout << "need tree" << endl;
            return;
        }
    }
    
    // Try to find subsequence (automation)
    int pos = 0;
    for(char c : t) {
        while(pos < s.length() && s[pos] != c) pos++;
        if(pos >= s.length()) {
            // Check if we can get t by array operations (swapping)
            sort(s.begin(), s.end());
            string t_sorted = t;
            sort(t_sorted.begin(), t_sorted.end());
            if(s.find(t_sorted) != string::npos) {
                if(t_sorted.size() == s.size()){
                    cout << "array" << endl;
                }else{
                    cout << "both" << endl;
                }
            } else {
                cout << "both" << endl;
            }
            return;

        }
       pos++;
    }
    
    cout << "automaton" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}