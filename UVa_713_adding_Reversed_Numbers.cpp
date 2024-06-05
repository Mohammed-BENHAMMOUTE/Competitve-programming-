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

void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    string s1, s2;
    
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int n1 = stoi(s1);
    int n2 = stoi(s2);
    long long an = n1 + n2;
    string ans = to_string(an);
    reverse(ans.begin(), ans.end());
    int i= 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }
    ans = ans.substr(i);
    cout << ans << endl;
}

int main()
{
    fastio();
    int t;
    cin >> t;
    cin.ignore();  // ignore the newline after the number of test cases
    while(t--) {
        solve();
    }
    return 0;
}