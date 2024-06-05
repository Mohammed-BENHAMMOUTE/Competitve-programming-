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
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int m; cin >> m;
    vector<int> d(m);
    for(int i = 0; i < m; i++){
        cin >> d[i];
    }

    if (count(b.begin(), b.end(), d[m-1]) == 0) {
        cout << "NO" << endl;
        return;
    }

    map<int, int> diff;
    for (int i = 0; i < m; i++) {
        diff[d[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (diff[b[i]] == 0) {
                cout << "NO" << endl;
                return;
            }
            diff[b[i]]--;
        }
    }

    cout << "YES" << endl;
    return;
}

int main()
{
    fastio();
    ll t;
    cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    };
    return 0;
}