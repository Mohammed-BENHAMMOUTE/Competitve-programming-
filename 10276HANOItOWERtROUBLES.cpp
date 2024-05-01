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
bool isSqure(int n)
{
    int x = sqrt(n);
    return x * x == n;
}

void solve()
{
    int n;cin >> n;
    vector<int> v(n+1,0);
    for(int x =1;;x++) {
        for(int i = 0; i < n+1; i++) {
            if(v[i] == 0 || isSqure(v[i] + x)) {
                v[i] = x;
                break;
            }
        };
        if(v[n]!= 0) {
            cout << x -1<< endl;
            return;
        };
    }

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