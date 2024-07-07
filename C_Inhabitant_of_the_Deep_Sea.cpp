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
    int n;cin >> n;
    ll k;cin >> k;
    deque<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    while(k > 0 && a.size() > 0)
    {
        if(a.size() == 1 )
        {
           if(a.front() <= k) count++;
             break;
        }
        ll temp = min(a.front(), a.back());
        if(k < 2*temp)
        {
            a.front() -= k/2+k%2;
            a.back() -= k/2;
            if(a.front() == 0)
            {
                a.pop_front();
                count++;
            };
            if(a.back() == 0)
            {
                a.pop_back();
                count++;
            };
            break;
        };
        k -= 2*temp;
        a.front() -= temp;
        a.back() -= temp;
        if(a.front() == 0)
        {
            a.pop_front();
            count++;
        }
        if(a.back() == 0)
        {
            a.pop_back();
            count++;
        }
    };
    cout << count << endl;
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