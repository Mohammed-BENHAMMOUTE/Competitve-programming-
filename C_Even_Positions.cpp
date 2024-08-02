#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc \
    ll tc; \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;

void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll countCost(const string& s) {
    ll cost = 0;
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            if (!st.empty()) {
                int openIndex = st.top();
                st.pop();
                cost += i - openIndex;
            }
        }
    }
    return cost;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != '_') {
            s[i] == '(' ? count++ : count--;
        } else {
            if (count > 0 || (i == n-1 && count == 0)) {
                s[i] = ')';
                count--;
            } else {
                s[i] = '(';
                count++;
            }
        }
    }
    
    cout << countCost(s) << endl;
}

int main() {
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}