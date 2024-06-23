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
    int q;cin >> q;
    set<ll> s1,s2;
    map<ll, int> m1,m2;
    for(int i = 0; i < q; i++)
    {
        char c; cin >>c;
        ll l ,r; cin >> l >> r;
        if(c=='+')
        {
            m1[l]++;
            m2[r]++;
            if(m1[l] == 1) s1.insert(l);
            if(m2[r] == 1) s2.insert(r);
        }
        else
        {
            m1[l]--;
            m2[r]--;
            if(m1[l] == 0)
            {
                s1.erase(s1.find(l));
            }
            if(m2[r] == 0)
            {
                s2.erase(s2.find(r));
            };
        };
        if(s1.empty() || i == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        ll a1 = *s1.rbegin();
        ll a2 = *s2.begin();
        // cout << a1 << " " << a2 << endl;
        if(a1 <= a2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        };
    };
    return;
}

int main()
{
    fastio();
    solve();

    return 0;
}