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
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    map<pair<int, int>, int> waste;
    for(int j = 0 ; j < k; j++) {
        int x, y; cin >> x >> y;
        waste[{x, y}] = -1;
    };
    map<int, string> mp;
    mp[0] = "Carrots";
    mp[1] = "Kiwis";
    mp[2] = "Grapes";
    mp[-1] = "Waste";
    for(int i = 0 ; i < t ; i++) {
        int x, y; cin >> x >> y;
        if(waste.count({x, y}) > 0) {
            cout << mp[-1] << endl;
        } else {
            int crops = ((x-1)*m + y - 1 - distance(waste.begin(), waste.lower_bound({x, y}))) % 3;
            cout << mp[crops] << endl;
        }
    };
}

int main()
{
    fastio();
    solve();
    return 0;
}