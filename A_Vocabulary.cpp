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
    string s; cin >> s;
    bool ok = false;
    for (int i = 1; i < (int)(s.size()); i++) {
        if (s[i] != s[0]) {
            swap(s[i], s[0]); 
            ok = true; 
            break;
        }
    }   
    if (!ok) {
        cout << "NO\n"; 
        return;
    }
    cout << "YES\n";
    cout << s << '\n';
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