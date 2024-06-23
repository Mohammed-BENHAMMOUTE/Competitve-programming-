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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    int grp = 0;

    while (true)
    {
        vector<int> to_erase;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && v[i].size() == 1)
            {
                to_erase.pb(i);
            }
        }

        if (to_erase.empty())
        {
            break;
        }

        for (int i : to_erase)
        {
            if (v[i].size() == 1)
            {
                int neighbor = v[i][0];
                v[neighbor].erase(remove(v[neighbor].begin(), v[neighbor].end(), i), v[neighbor].end());
                visited[i] = true;
                v[i].clear(); 
            }
        }

        grp++;
    }

    cout << grp << endl;
}

int main()
{
    fastio();
    solve();

    return 0;
}
