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
};
void solve()
{
    int n;
    ll l;
    cin >> n >> l;
    deque<int> v;
    for(int i = 0; i < n; i++) 
    {
        int x; cin >> x;
        v.push_back(x);
    };
    sort(v.begin(), v.end());

    double mx = max((double)v[0], (double)(l - v.back()));

    for(int i = 0; i < v.size() - 1; i++) 
    {
        mx = max(mx, (v[i+1] - v[i]) / 2.0);
    };
    cout << fixed << setprecision(10) << mx << endl;
};
int main()
{
    fastio();
    solve();
    return 0;
}