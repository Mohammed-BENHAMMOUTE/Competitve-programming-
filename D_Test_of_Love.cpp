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
    int n, m, k;
    cin >> n >> m >> k;
    string a;
    cin >> a;

    if (m >= n) {
        cout << "YES" << endl;
        return;
    }

    int curr = -1;
    bool inWater = false;
    int swam = 0;

    while (curr < n-1) {
        int lastLog = -1;
        int lastWater = -1;

        for (int i = curr + 1; i < n && i <= curr + m; i++) {
            if (a[i] == 'L') lastLog = i;
            if (a[i] == 'W') lastWater = i;
        }

        if (inWater) {
            // curr++;
            swam++;
            if (a[curr] == 'W') {
                curr++;
                inWater = true;
            } else if (a[curr] == 'L') {
                
                inWater = false;
            } else if (curr >= n) {
                cout << "YES" << endl;
                return;
            }
            if (a[curr] == 'C') {
                cout << "NO" << endl;
                return;
            }
            continue;
        } else {
            if (lastLog != -1) {
                curr = lastLog;
                inWater = false;
            } else if (lastLog == -1 && lastWater != -1) {
                curr = lastWater;
                inWater = true;
            }
            if (lastLog == -1 && lastWater == -1) {
                cout << "NO" << endl;
                return;
            };
        };
    };
    if (swam <= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    };
};

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}
