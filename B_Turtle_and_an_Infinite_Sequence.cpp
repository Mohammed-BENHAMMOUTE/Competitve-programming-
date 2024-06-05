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
    ll n, m;
    cin >> n >> m;
    ll end = n + m;
    ll start = n - m >= 0 ? n - m : 0;

    if (start == end) {
        cout << start << endl;
        return;
    }

    // Compute the highest differing bit position
    // ;)
    ll xor_val = start ^ end;
    ll msb_pos = 0;
    while (xor_val > 0) {
        xor_val >>= 1;
        msb_pos++;
    }

    // Create the mask with all bits set to 1 from msb_pos downwards
    ll mask = (1LL << msb_pos) - 1;

    // Apply the mask to get the result
    ll ans = end | mask;

    cout << ans << endl;
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
