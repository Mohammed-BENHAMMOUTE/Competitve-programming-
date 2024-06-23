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
#define what(x) cout << #x << " = " << x << '\n'
void fastio()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n == 2) {
        cout << (s[0] - '0') * 10 + (s[1] - '0') << endl;
        return;
    }

    ll minSum = LLONG_MAX;
    for (int st = 0; st < n - 1; st++) {
        ll sum = 0;
        
        int curr = 10*(s[st] - '0') + (s[st + 1] - '0');
        if (curr != 1) sum += curr; 
        if (curr == 0) {
            cout << 0 << endl;
            return;
        };
        for (int i = 0; i < st; i++) {
            if(s[i] == '0')
            {
                cout << 0 << endl;
                return;
            }
            if (s[i] != '1' || sum == 0) sum += s[i] - '0';
        }
        for (int i = st + 2; i < n; i++) {
            if(s[i] == '0')
            {
                cout << 0 << endl;
                return;
            }
            if (s[i] != '1') sum += s[i] - '0';

        };
        minSum = min(minSum, sum);
    }

    cout << minSum << endl;
}

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
