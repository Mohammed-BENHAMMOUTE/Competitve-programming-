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
    ll h, n;
    cin >> h >> n;
    vector<ll> damages(n);
    vector<ll> cooldowns(n);
    
    for (ll i = 0; i < n; ++i) cin >> damages[i];
    for (ll i = 0; i < n; ++i) cin >> cooldowns[i];

    vector<pair<ll, ll>> damage_and_index(n);
    for (ll i = 0; i < n; ++i) {
        damage_and_index[i] = mp(damages[i], i);
    }
    sort(damage_and_index.rbegin(), damage_and_index.rend()); // Sort by damage in descending order

    vector<ll> next_available_turn(n, 0);
    ll turn = 0;

    while (h > 0) {
        ++turn;
        ll total_damage = 0;
        ll earliest_next_turn = LLONG_MAX;
        
        for (const auto& p : damage_and_index) {
            ll damage = p.first;
            ll i = p.second;
            if (next_available_turn[i] <= turn) {
                total_damage += damage;
                next_available_turn[i] = turn + cooldowns[i];
            }
            if (next_available_turn[i] < earliest_next_turn) {
                earliest_next_turn = next_available_turn[i];
            }
        }
        
        if (total_damage == 0) {  // If no attacks are available this turn
            turn = earliest_next_turn - 1;  // Move to the turn when the first attack will be available again
        } else {
            h -= total_damage;
        };
    };
    cout << turn << endl;
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
