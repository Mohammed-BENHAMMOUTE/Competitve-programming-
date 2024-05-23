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

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    // If the sum of scores is odd, print -1 and return
    if ((a + b + c) % 2 == 1) {
        cout << -1 << "\n";
        return;
    }

    int p[] = {a, b, c};
    int count = 0;

    // Decrease p2 and p3 until p2 becomes 0, and keep track of the count
    while (p[1] != 0) {
        count++;
        p[2]--;
        p[1]--;
        sort(p, p + 3);
    }

    // Print the count
    cout << count << "\n";
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