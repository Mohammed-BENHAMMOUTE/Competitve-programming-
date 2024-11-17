#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
const string t = "1100";

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int kmp(string s) 
{
    if (s.size() < t.size())
        return 0;

    int count = 0;

    int n = s.size(), m = t.size();
    vector<int> lps(m + 1, 0);
    int len = 0, i = 1, j;
    while (i < m) {
        if (t[i] == t[len]) lps[i++] = ++len;
        else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }

    i = 0; j = 0;
    while (i < n) {
        if (t[j] == s[i]) { j++; i++; }

        if (j == m) {
            count++;
            j = lps[j - 1];
        }
        else if (i < n && t[j] != s[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return count;
}

void solve()
{
    string s; 
    cin >> s;
    int q; 
    cin >> q;
    int count = kmp(s);
    while (q > 0) {
        int i, x;
        cin >> i >> x;
        i--;
        int start = max(0, i - 4);
        int end = min(static_cast<int>(s.size()), i + 4);
        int oldCount = kmp(s.substr(start, end - start));
        s[i] = '0' + x;
        int newCount = kmp(s.substr(start, end - start));
        count = newCount-oldCount + count;
        if (count > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        q--;
    }
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}