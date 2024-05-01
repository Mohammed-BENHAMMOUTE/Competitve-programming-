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
    ll n; cin >> n;
    ll mx= 0;
    for(int i =0; i<n; i++) {
        ll k; cin >> k;
        ll a; cin >> a;
        ll temp2 = ceil(log2(ceil(sqrt(a))));
        if(temp2 == 0) {
            temp2++;
        };
        ll temp = temp2+k;

        mx = max(mx, temp);
    };
    cout<< mx << endl;

}

int main()
{
    solve();

    return 0;
}